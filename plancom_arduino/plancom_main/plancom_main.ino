#include "plancom_library.h"
#include "plancom_pin_setting.h"
#include "plancom_library_setting.h"


void Send_CMD(void) {
  unsigned int i;
  for(i=0; i<4; i++) {
    mySerial.write(Send_data[i]);
    delay(1);
  }
}
unsigned char Checksum_cal(void) {
  unsigned char count, SUM=0;
  for(count=0; count<7; count++) {
     SUM += Receive_Buff[count];
  }
  return 256-SUM;
}


void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(11,OUTPUT);
  
  //블루투스 쓰고 싶을 땐 mySerial 주석처리 요망
  bluetooth.begin(9600); 
//  mySerial.begin(9600);

  
  dht.begin();  
  pm2008_i2c.command();

  
  pm2008_i2c.begin();

                                                                                /*LED 세팅*/
  pixels.begin();  // 네오픽셀 제어 시작
  pixels.show();  // 네오픽셀 초기화
  
  pinMode(MOTOR, OUTPUT); //motor setting


                                                                                /*센서값 통신 세팅*/
  time_previous = millis();
  time_bluetooth_previous = millis();
}

void loop() {
  
                                                                                  //센서값 갱신 시간(delay를 쓰면 동시 진행 X -> 블루투스 통신에 지연이 생김)
  time_current = millis();

  
                                                                                  /*각종 센서값 받아오기*/
  h = dht.readHumidity();                                                         //습도값을 h에 저장
  t = dht.readTemperature();                                                      //온도값을 t에 저장
  hic = dht.computeHeatIndex(t, h, false);                                        //섭씨 온도값을 hic에 저장
  
  uint8_t ret = pm2008_i2c.read();                                                //미세먼지 센서값 받아와 ret에 저장


                                                                                  
                                                                                  /*토양 습도 값 받아와 보정 (1의자리 수를 0으로)*/
  water = analogRead(Soil_PIN);                                                   //토양 습도 센서값 water에 저장
  water = water / 10;                                                             //1의 자리 수를 덜어냄 
  water = water * 10;


                    
  bluetoothSignal();                                                              /*bluetooth 값 받아오기*/
  Co2_Setting();
  ECSetting();                                                                    /*EC sensor 세팅*/


  


                                                                                  /*현실시간 1초가 지나면 세븐세그먼트 모니터에 토양습도 값 표기*/
  if(time_current - time_previous >= 1000){
      printLED();
      printDHT();
      paintEC();
      Serial.print("Water : ");
      Serial.println(water);
      
      Serial.print("WaterMax : ");
      Serial.println(waterMax);

     Serial.write("   PPM : ");
     Serial.println(PPM_Value);
     
    if (ret == 0) {
      Serial.print("PM 1.0 (GRIMM) : ");
      Serial.println(pm2008_i2c.pm1p0_grimm);
    }

      
      Serial.println();
  }

                                      //타이머 초기화
  time_previous = time_current;


}

#include "plancom_library.h"
#include "plancom_pin_setting.h"
#include "plancom_library_setting.h"

void setup() {
  
  Serial.begin(9600);
       
  //블루투스 쓰고 싶을 땐 mySerial 주석처리 요망
  bluetooth.begin(9600); 

  dht.begin();

  pm2008_i2c.begin();

                                                                                /*LED 세팅*/
  pixels.begin();  // 네오픽셀 제어 시작
  pixels.show();  // 네오픽셀 초기화
  
  pinMode(MOTOR, OUTPUT); //motor setting

  cm1106_i2c.begin();
  
                                                                                /*센서값 통신 세팅*/
  time_previous = millis();
  time_bluetooth_previous = millis();
}

void loop() {
  
                                                                               //센서값 갱신 시간(delay를 쓰면 동시 진행 X -> 블루투스 통신에 지연이 생김)

  
                                                                                  /*각종 센서값 받아오기*/
  h = dht.readHumidity();                                                         //습도값을 h에 저장
  t = dht.readTemperature();                                                      //온도값을 t에 저장
  hic = dht.computeHeatIndex(t, h, false);                                        //섭씨 온도값을 hic에 저장
  
  uint8_t ret_dust = pm2008_i2c.read();                                                //미세먼지 센서값 받아와 ret에 저장
  uint8_t ret_co2 = cm1106_i2c.measure_result();


                                                                          
                                                                                  /*토양 습도 값 받아와 보정 (1의자리 수를 0으로)*/
  water = analogRead(Soil_PIN);                                                   //토양 습도 센서값 water에 저장
  water = water / 10;                                                             //1의 자리 수를 덜어냄 
  water = water * 10;


                    
  bluetoothSignal();                                                              /*bluetooth 값 받아오기*/
  ECSetting();                                                                    /*EC sensor 세팅*/

  
   if ( water > 800){
      digitalWrite(MOTOR, HIGH);
    }else{
      digitalWrite(MOTOR, LOW);
    }


                                                                                  /*현실시간 1초가 지나면 세븐세그먼트 모니터에 토양습도 값 표기*/
  if(time_previous + 2000 < millis()){
   
    Serial.print("LED Color : ");
      if (count == 0) {
        Serial.println("LED Off");
      } else if (count == 1) {
        Serial.println("Red");
      } else if (count == 2) {
        Serial.println("Orange");
      } else if (count == 3) {
        Serial.println("Yello");
      } else if (count == 4) {
        Serial.println("Green");
      } else if (count == 5) {
        Serial.println("Blue");
      } else if (count == 6) {
        Serial.println("Perple");
      } else if (count == 7) {
        Serial.println("White");
      } else{
        Serial.println("nan");
      }
      
      Serial.print("temperature:");
      Serial.print(hic);
      Serial.print(" C deg");
      Serial.print("       ");
      Serial.print(" humidity:");
      Serial.print(h);
      Serial.print(" %");
      Serial.println();
      
      //시리얼 모니터 출력
      Serial.print("EC:");
      Serial.print(ecValue, 2);
      Serial.print("ms/cm");
      Serial.print("                   ");
    
    
      if (ecValue >= 1.2) {                                         //EC센서 값 1.2 이상 : 양호
        Serial.println("영양상태 양호");
      } else if (ecValue >= 0.7 && ecValue < 1.2) {                 //EC센서 값 1.2 미만 ~ 0.7 이상 : 주의
        Serial.println("영양상태 주의");
      } else if (ecValue < 0.7) {                                   //EC센서 값 0.7 미만 : 위험
        Serial.println("영양상태 위험");
      }
      
          Serial.print("Water : ");
          Serial.println(water);
          
          Serial.print("WaterMax : ");
          Serial.println(waterMax);
         
        if (ret_dust == 0) {
          Serial.print("PM 1.0 (GRIMM) : ");
          Serial.println(pm2008_i2c.pm1p0_grimm);
        }
    
        if (ret_co2 == 0) {
        Serial.print("Co2 : ");
        Serial.println(cm1106_i2c.co2);
        Serial.println("Status >>");
    
    
    #if defined(CM1107)
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_PREHEATING)) {
          Serial.println("Preheating");
        } else {
          Serial.println("Preheat complete");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_OPERATING_NORMAL)) {
          Serial.println("Sensor Error");
        } else {
          Serial.println("Operating normal");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_OVER_MEASUREMENT_RANGE)) {
          Serial.println("Over Measurement Range");
        } else {
          Serial.println("Normal Measurement Range");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_LESS_THAN_MEASUREMENT_RANGE)) {
          Serial.println("Less than Measurement Range");
        } else {
          Serial.println("Normal Measurement Range");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_CALIBRATED)) {
          Serial.println("Non-calibrated");
        } else {
          Serial.println("Calibrated");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_LIGHT_AGING)) {
          Serial.println("Light Aging");
        } else {
          Serial.println("Light Normal");
        }
    
        if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_DRIFT)) {
          Serial.println("Drift");
        } else {
          Serial.println("Non-Drift");
        }
    
        
    #else
        switch (cm1106_i2c.status) {
          case CM1106_I2C_STATUS_PREHEATING: {
              Serial.println("Preheating");
              break;
            }
          case CM1106_I2C_STATUS_NORMAL_OPERATION: {
              Serial.println("Normal operation");
              break;
            }
          case CM1106_I2C_STATUS_OPERATING_TROUBLE: {
              Serial.println("Operating trouble");
              break;
            }
          case CM1106_I2C_STATUS_OUT_OF_FS: {
              Serial.println("Out of FS");
              break;
            }
          case CM1106_I2C_STATUS_NON_CALIBRATED: {
              Serial.println("Non calibrated");
              break;
            }
        }
    #endif
        
    
    
        
      }
      delay(1000);
      
      Serial.println();
  }
                                                                                  /*현실시간 1초가 지나면 세븐세그먼트 모니터에 토양습도 값 표기*/
  if(time_bluetooth_previous + 2000 < millis()){
      
      //시리얼 모니터 출력
      bluetooth.print(ecValue, 2);                   //ec센서
      bluetooth.print(",");

          
      
      bluetooth.print(hic);                       //섭씨온도
      bluetooth.print(",");
      bluetooth.print(h);                         //습도
      bluetooth.print(",");
      
    
    
/*      if (ecValue >= 1.2) {                                         //EC센서 값 1.2 이상 : 양호
        Serial.println("영양상태 양호");
      } else if (ecValue >= 0.7 && ecValue < 1.2) {                 //EC센서 값 1.2 미만 ~ 0.7 이상 : 주의
        Serial.println("영양상태 주의");
      } else if (ecValue < 0.7) {                                   //EC센서 값 0.7 미만 : 위험
        Serial.println("영양상태 위험");
      }
*/      
         
        if (ret_dust == 0) {                                          //미세먼지
          bluetooth.print(pm2008_i2c.pm1p0_grimm);
          bluetooth.print(",");
        }
    
        if (ret_co2 == 0) {                                           //Co2
        bluetooth.print(cm1106_i2c.co2);
        bluetooth.print(",");
          
        bluetooth.print(water);
        bluetooth.print(",");
      }
      delay(1000);
  }

}

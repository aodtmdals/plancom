//AT로 확인하삼

void bluetoothSignal() {
  /*
    if (bluetooth.available()) {
    Serial.write(bluetooth.read());  //블루투스측 내용을 시리얼모니터에 출력
    }
    if (Serial.available()) {
    bluetooth.write(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
    }
  */


                                                                                                            /*bluetooth data save*/
  //bluetooth 통신을 통해 받아들인 문자열을 data에 저장
  while (bluetooth.available()) {
    char BT_buffer = (char)bluetooth.read();
    data += BT_buffer;
    delay(50);
  }
                                                                                                            /*받아온 센서를 블루투스로 통신해 보내줌*/
  //paintBluetoothSensorValue();


  if (not(data == ""))                                                                                     //data 값이 있다면
  {
    Serial.println("input value: " + data);                                                                //시리얼모니터에 data값 출력

                                                                                                            //LED 색깔 조절에 대한 데이터가 들어오면 LED_color 변수에 저장해 data 값이 변해도 LED가 꺼지지 않게 함
    if (data == "L0" || data == "L1" || data == "L2" || data == "L3" 
    || data == "L4" || data == "L5" || data == "L6" || data == "L7") {
      LED_color = data;
      
      if (LED_color == "L0") {
        LED_Control(0);
      }
      if (LED_color == "L1") {
        LED_Control(1);
      }
      if (LED_color == "L2") {
        LED_Control(2);
      }
      if (LED_color == "L3") {
        LED_Control(3);
      }
      if (LED_color == "L4") {
        LED_Control(4);
      }
      if (LED_color == "L5") {
        LED_Control(5);
      }
      if (LED_color == "L6") {
        LED_Control(6);
      }
      if (LED_color == "L7") {
        LED_Control(7);
      }
    }
                                                                                                              //펌프 조절에 대한 데이터 값이 들어오면 waterMax 변수에 저장해 펌프를 ON/OFF함
    if(data.toInt() >= 0 && data.toInt() <= 999){
     waterMax = data.toInt();
     motor_Move(waterMax);
    }



                                                                                                                /*data reset*/
    data = "";                                                                                                  //data 변수값 초기화
  }
  time_bluetooth_current = millis();
}



void paintBluetoothSensorValue() {
                                                                                                                //현실 시간 2초마다 센서값을 보냄
  if (time_bluetooth_current - time_bluetooth_previous >= 2000) {
    printBluetoothLED();
    printBluetoothDHT();
    paintBluetoothEC();
    paintBluetoothDust();
    
    time_bluetooth_previous = time_bluetooth_current;
  }
}

                                                                  /*모터에 관한 함수들을 모아둔 곳*/
void motor_Move(int waterMax){
  if(waterMax >= 1 && water <= 999){                              //블루투스로 1~999데이터가 들어오면 
    if(waterMax < water){                                         //토양습도센서값과 비교해 습도가 부족하면 모터 ON
      digitalWrite(MOTOR, HIGH);
    }else {                                                        //충분하거나 충분해지면 모터 OFF
      digitalWrite(MOTOR, LOW);
    }
  }
  else  if(waterMax == 0){                                          //블루투스로 0 데이터가 들어오면 자동 물주기 ON
   if ( water > 800){
      digitalWrite(MOTOR, HIGH);
    }else{
      digitalWrite(MOTOR, LOW);
    }
  }
}

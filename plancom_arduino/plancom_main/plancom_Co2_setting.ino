void Co2_Setting(){
  Serial.print("Sending...");
  Send_CMD();
  while(1) {
    if(mySerial.available()) { 
       Receive_Buff[recv_cnt++] = mySerial.read();
      if(recv_cnt ==8){recv_cnt = 0; break;}
    }
  } 
  
  if(Checksum_cal() == Receive_Buff[7]) {
     PPM_Value = Receive_Buff[3]<<8 | Receive_Buff[4];
  }
   else {
    Serial.write("CHECKSUM Error");
  }
}

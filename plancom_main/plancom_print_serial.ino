                                                                                    /*시리얼 모니터에 센서값 출력하는 걸 모아둔 곳*/
void printLED() {
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
  }
}


/*EC 센서 값 나타내기*/
void paintEC() {
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
}

void printDHT() {
  Serial.print("temperature:");
  Serial.print(hic);
  Serial.print(" C deg");
  Serial.print("       ");
  Serial.print(" humidity:");
  Serial.print(h);
  Serial.print(" %");
  Serial.println();
}

/*블루투스 통신으로 데이터 값을 보내는 함수를 모아둔 곳*/

void printBluetoothDHT() {
  bluetooth.print("Temperature:" );
  bluetooth.print(hic, 1);
  bluetooth.print(" C deg");
  bluetooth.print("      ");
  bluetooth.print("Humidity: " );
  bluetooth.print(h, 1);
  bluetooth.print(" %");
  bluetooth.println("");

}


void paintBluetoothEC() {
  bluetooth.print("EC:");
  bluetooth.print(ecValue, 2);
  bluetooth.print("ms/cm");
  bluetooth.print("              "  );


  if (ecValue >= 1.2) {                                         //EC센서 값 1.2 이상 : 양호
    bluetooth.println("영양상태 양호");
  } else if (ecValue >= 0.7 && ecValue < 1.2) {                 //EC센서 값 1.2 미만 ~ 0.7 이상 : 주의
    bluetooth.println("영양상태 주의");
  } else if (ecValue < 0.7) {                                   //EC센서 값 0.7 미만 : 위험
    bluetooth.println("영양상태 위험");
  }
}


void paintBluetoothDust() {

}

void printBluetoothLED() {
  bluetooth.print("LED Color : ");
  if (count == 0) {
    bluetooth.println("LED Off");
  } else if (count == 1) {
    bluetooth.println("Red");
  } else if (count == 2) {
    bluetooth.println("Orange");
  } else if (count == 3) {
    bluetooth.println("Yello");
  } else if (count == 4) {
    bluetooth.println("Green");
  } else if (count == 5) {
    bluetooth.println("Blue");
  } else if (count == 6) {
    bluetooth.println("Perple");
  } else if (count == 7) {
    bluetooth.println("White");
  }
}

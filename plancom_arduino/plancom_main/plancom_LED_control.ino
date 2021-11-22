                                                                                      /*LED 제어 함수를 모아둠*/
void LED_Control(int count) {
  if (count == 0)                                                                 //LED OFF
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)  ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }

  if (count == 1)                                                                 //RED
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(255, 0, 0)  ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }

  if (count == 2)                                                                  //ORANGE
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(255, 50, 0) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }

  if (count == 3)                                                                  //YELLO
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(255, 150, 0) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }
  if (count == 4)                                                                  //GREEN
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(0, 255, 0) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }
  if (count == 5)                                                                  //BLUE
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(0, 0, 255) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }
  if (count  == 6)                                                                //PERPLE
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(100, 0, 255) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }
  if (count  == 7)  //WHITE
  {
    for ( int i = 0; i < NUMPIXELS; i++ ) { // 네오픽셀 동작 (1번째부터 8번째까지)
      pixels.setPixelColor(i, pixels.Color(255, 255, 255) ); // 네오픽셀 색 지정
      pixels.show(); // 네오픽셀 ON
    }
  }
}

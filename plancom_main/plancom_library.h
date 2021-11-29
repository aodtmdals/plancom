/*bluetooth, 온습도, 미세먼지 library*/
#include <SoftwareSerial.h>               //bluetooth 사용 라이브러리 호출
#include <DHT.h>                          //DHT 라이브러리 호출
#include <pm2008_i2c.h>                   //미세먼지 라이브러리 호출
#include <cm1106_i2c.h>
#include <Wire.h>

/*네오픽셀 LED library*/
#include <Adafruit_NeoPixel.h>            // 네오픽셀 LED 사용하기 위해 헤더파일 선언


/*EC sensor library*/
#include <DFRobot_EC.h>
#include <EEPROM.h>

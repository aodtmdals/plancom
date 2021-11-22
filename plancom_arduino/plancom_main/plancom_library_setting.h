                                                                      /*bluetooth, DHT, EC, NeoPixel LED setting*/
SoftwareSerial bluetooth(BT_RXD, BT_TXD);                             //bluetooth setting
SoftwareSerial mySerial(13, 11);                                      //Co2Sensor setting

DHT dht(DHTPIN, DHTTYPE);                                             //DHT 설정(12,DHT11)
DFRobot_EC ec;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

PM2008_I2C pm2008_i2c;

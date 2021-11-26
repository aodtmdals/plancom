/*bluetooth PIN setting*/
#define BT_RXD 6
#define BT_TXD 7


/*먼지, EC, 토양수분, 모터릴레이 PIN setting*/
#define EC_PIN A1                             //EC pin setting
#define Soil_PIN A3                           //soli pin setting
#define MOTOR 11                              //motor pin setting


/*DHT pin setting*/
#define DHTPIN 8                              // DHT pin setting
#define DHTTYPE DHT11                          // DHT11 온습도 센서 사용

/*LED pin setting*/
#define RGB_PIN 13                              //LED pin setting
int NUMPIXELS = 16;                              // 네오픽셀 개수
String LED_color = "";                          //LED 색깔 변수
int count = 0;      //색깔 저장


/*DHT 센서값 변수*/
float h = 0, t = 0, hic = 0;

/*EC센서 변수들(온도는 추후 온도센서와 연동 예정)*/
float voltage = 0, ecValue = 0, temperature = 0;


int water = 0 ; // water 변수 선언
int EC = 0 ; // EC 변수 선언

/*bluetooth 데이터값*/
String data = "";       //블루투스 데이터



unsigned long time_previous, time_bluetooth_previous;

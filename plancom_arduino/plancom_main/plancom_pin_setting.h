/*bluetooth PIN setting*/
#define BT_RXD 7
#define BT_TXD 6


/*먼지, EC, 토양수분, 모터릴레이 PIN setting*/
#define EC_PIN A1                             //EC pin setting
#define Soil_PIN A3                           //soli pin setting
#define MOTOR 11                              //motor pin setting
int waterMax = 0;                             //자동 물주기 변수


/*DHT pin setting*/
#define DHTPIN 12                              // DHT pin setting
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


/*먼지 센서 setting*/


unsigned long time_previous, time_current, time_bluetooth_previous, time_bluetooth_current;

/*Co2센서 변수들*/
unsigned char Send_data[4] = {0x11,0x01,0x01,0xED};
unsigned char Receive_Buff[8];
unsigned char recv_cnt = 0;
unsigned int PPM_Value;
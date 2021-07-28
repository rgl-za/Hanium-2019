//PR테스트
#include "DHT.h"
#include <Servo.h>
#include "LedControl.h"

#define DHTPIN 2     // DHT11이 연결된 핀

#define DHTTYPE DHT11   // DHT 11, DHT시리즈중 11을 선택합니다.

#include <Adafruit_NeoPixel.h> // Adafruit_NeoPixel 라이브러리 include, 필수 선언!!!
#define PIN 6 // 결정하여야 할 변수 → 데이터 출력핀 번호
#define NUMPIXELS 30 // 결정하여야 할 변수 → LED 개수

int h;
int danger_h=90;
int danger_gas=200;
int GasPin = A0; 
DHT dht(DHTPIN, DHTTYPE);
Servo servo;
Servo servo_2;
Servo servo_3;
Servo servo_4;
int servoPin_1 = 3;
int servoPin_2 = 4;
int servoPin_3 = 8;
int servoPin_4 = 9;
int angle = 0;
int angle_1 = 0;// servo position in degrees
int eye = 0;
int led_1 = 0;
LedControl lc = LedControl(12, 11, 10, 2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// pixels 는 Adafrut_NeoPixel 구조체의 형태를 가짐
// LED의 개수는 10(NUMPIXELS)이며,
// WS2812B 타입(NEO_GRB + NEO_KHZ800)임

void D(){
  //delay(3000);

  h = dht.readHumidity();// 습도를 측정합니다.
  float t = dht.readTemperature();// 온도를 측정합니다.
  float f = dht.readTemperature(true);// 화씨 온도를 측정합니다.

  // 값 읽기에 오류가 있으면 오류를 출력합니다.
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // 보정된 화씨 값을 가져옵니다.
  float hif = dht.computeHeatIndex(f, h);
  // 보정된 섭씨 값을 가져옵니다.
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  if(h>danger_h){
    servo_1();
    servo_5();
    eye = 1;
    led_1 = 1;
  }
  else {
    eye = 0;
    led_1 = 0;
  }
 }
void servo_1(){ //날개
  // rotate from 0 to 180 degrees
 int plus=1;
 for(angle = 0 ; angle < 90; angle+=plus) 
  {
    servo.write(angle);
    servo_2.write(angle);
    delay(13);
    if(angle>=178){
      plus*=-1;
     }
    if(angle<0){
       D();
       gas_danger();
       break;
     }
  }
  Serial.println("날개 확인");
}

void servo_5(){ //꼬리
  // rotate from 0 to 180 degrees
 int plus=1;
 for(angle = 0, angle_1=180 ; angle < 180, angle_1>0; angle+=plus,angle_1-=plus) 
  {
    servo_3.write(angle);
    servo_4.write(angle_1);
    delay(13);
    if(angle>=178){
      plus*=-1;
     }
    if(angle<0){
    
       break;
     }
  }
 
  Serial.println("꼬리 확인");
}

void gas_danger(){                    
 Serial.println(analogRead(GasPin));  
 delay(10);  // 10ms 대기
 if(analogRead(GasPin)> danger_gas){
     servo_1(); 
     servo_5();
     eye = 1;
     led_1 = 2;
  }
  else{
    eye = 0;
    led_1 = 0;
   }
}

void eyes(){
 byte happy[] =
{
  B00000000,
  B00000000,
  B00000000,
  B01100011,
  B00110110,
  B00011100,
  B00001000,
  B00000000
};

byte cry[] =
{
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B11111111,
  B11111111,
  B00000000
};
for (int i = 0; i < 8; i++){
  if(eye == 1){
    lc.setRow(0, i, cry[i]);
    
  }
  else
    lc.setRow(0, i, happy[i]);
  }
delay(3000);
}


void led(){
  if(led_1 == 0){
  for(int i=0; i<NUMPIXELS; i++){ // 전체 LED에 대하여
    pixels.setPixelColor(i, pixels.Color(150,75,0)); // Green 컬러(중간 밝기) 준비.
    pixels.show(); // 데이터 전송
  }
  }
  else if(led_1 == 1){
  for(int i=0; i<NUMPIXELS; i++){ // 전체 LED에 대하여
    pixels.setPixelColor(i, pixels.Color(0,15,240)); // Green 컬러(중간 밝기) 준비.
    pixels.show(); // 데이터 전송
  }
  }
  else if(led_1 == 2){
  for(int i=0; i<NUMPIXELS; i++){ // 전체 LED에 대하여
    pixels.setPixelColor(i, pixels.Color(255,30,0)); // Green 컬러(중간 밝기) 준비.
    pixels.show(); // 데이터 전송
  }
  }
}


void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(GasPin ,INPUT);               // 아날로그 핀 A0를 입력모드로 설정
  servo.attach(servoPin_1);
  servo_2.attach(servoPin_2);
  servo_3.attach(servoPin_3);
  servo_4.attach(servoPin_4);
  dht.begin();
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
  pixels.begin(); // Adafruit_Neopixel 라이브러리 초기화
}

void loop() {
  D();
  gas_danger();
  eyes();
  led();
}
  

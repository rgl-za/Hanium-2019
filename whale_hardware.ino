{\rtf1\ansi\ansicpg949\cocoartf2578
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;\f1\fnil\fcharset129 AppleSDGothicNeo-Regular;\f2\fnil\fcharset0 Menlo-Regular;
\f3\froman\fcharset0 Times-Roman;\f4\fnil\fcharset129 NanumGothic;}
{\colortbl;\red255\green255\blue255;\red52\green52\blue52;\red255\green255\blue255;}
{\*\expandedcolortbl;;\cssrgb\c26667\c26667\c26667;\cssrgb\c100000\c100000\c100000;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl360\qj\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include "DHT.h"\
#include <Servo.h>\
#include "LedControl.h"\
\
#define DHTPIN 2     // DHT11
\f1 \'c0\'cc
\f0  
\f1 \'bf\'ac\'b0\'e1\'b5\'c8
\f0  
\f1 \'c7\'c9
\f0 \
\
#define DHTTYPE DHT11   // DHT 11, DHT
\f1 \'bd\'c3\'b8\'ae\'c1\'ee\'c1\'df
\f0  11
\f1 \'c0\'bb
\f0  
\f1 \'bc\'b1\'c5\'c3\'c7\'d5\'b4\'cf\'b4\'d9
\f0 .\
\
#include <Adafruit_NeoPixel.h> // Adafruit_NeoPixel 
\f1 \'b6\'f3\'c0\'cc\'ba\'ea\'b7\'af\'b8\'ae
\f0  include, 
\f1 \'c7\'ca\'bc\'f6
\f0  
\f1 \'bc\'b1\'be\'f0
\f0 !!!\
#define PIN 6 // 
\f1 \'b0\'e1\'c1\'a4\'c7\'cf\'bf\'a9\'be\'df
\f0  
\f1 \'c7\'d2
\f0  
\f1 \'ba\'af\'bc\'f6
\f0  
\f2 \uc0\u8594 
\f0  
\f1 \'b5\'a5\'c0\'cc\'c5\'cd
\f0  
\f1 \'c3\'e2\'b7\'c2\'c7\'c9
\f0  
\f1 \'b9\'f8\'c8\'a3
\f0 \
#define NUMPIXELS 30 // 
\f1 \'b0\'e1\'c1\'a4\'c7\'cf\'bf\'a9\'be\'df
\f0  
\f1 \'c7\'d2
\f0  
\f1 \'ba\'af\'bc\'f6
\f0  
\f2 \uc0\u8594 
\f0  LED 
\f1 \'b0\'b3\'bc\'f6
\f0 \
\
int h;\
int danger_h=90;\
int danger_gas=200;\
int GasPin = A0; \
DHT dht(DHTPIN, DHTTYPE);\
Servo servo;\
Servo servo_2;\
Servo servo_3;\
Servo servo_4;\
int servoPin_1 = 3;\
int servoPin_2 = 4;\
int servoPin_3 = 8;\
int servoPin_4 = 9;\
int angle = 0;\
int angle_1 = 0;// servo position in degrees\
int eye = 0;\
int led_1 = 0;\
LedControl lc = LedControl(12, 11, 10, 2);\
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);\
// pixels 
\f1 \'b4\'c2
\f0  Adafrut_NeoPixel 
\f1 \'b1\'b8\'c1\'b6\'c3\'bc\'c0\'c7
\f0  
\f1 \'c7\'fc\'c5\'c2\'b8\'a6
\f0  
\f1 \'b0\'a1\'c1\'fc
\f0 \
// LED
\f1 \'c0\'c7
\f0  
\f1 \'b0\'b3\'bc\'f6\'b4\'c2
\f0  10(NUMPIXELS)
\f1 \'c0\'cc\'b8\'e7
\f0 ,\
// WS2812B 
\f1 \'c5\'b8\'c0\'d4
\f0 (NEO_GRB + NEO_KHZ800)
\f1 \'c0\'d3
\f0 \
\
void D()\{\
  //delay(3000);\
\
  h = dht.readHumidity();// 
\f1 \'bd\'c0\'b5\'b5\'b8\'a6
\f0  
\f1 \'c3\'f8\'c1\'a4\'c7\'d5\'b4\'cf\'b4\'d9
\f0 .\
  float t = dht.readTemperature();// 
\f1 \'bf\'c2\'b5\'b5\'b8\'a6
\f0  
\f1 \'c3\'f8\'c1\'a4\'c7\'d5\'b4\'cf\'b4\'d9
\f0 .\
  float f = dht.readTemperature(true);// 
\f1 \'c8\'ad\'be\'be
\f0  
\f1 \'bf\'c2\'b5\'b5\'b8\'a6
\f0  
\f1 \'c3\'f8\'c1\'a4\'c7\'d5\'b4\'cf\'b4\'d9
\f0 .\
\
  // 
\f1 \'b0\'aa
\f0  
\f1 \'c0\'d0\'b1\'e2\'bf\'a1
\f0  
\f1 \'bf\'c0\'b7\'f9\'b0\'a1
\f0  
\f1 \'c0\'d6\'c0\'b8\'b8\'e9
\f0  
\f1 \'bf\'c0\'b7\'f9\'b8\'a6
\f0  
\f1 \'c3\'e2\'b7\'c2\'c7\'d5\'b4\'cf\'b4\'d9
\f0 .\
  if (isnan(h) || isnan(t) || isnan(f)) \{\
    Serial.println("Failed to read from DHT sensor!");\
    return;\
  \}\
\
  // 
\f1 \'ba\'b8\'c1\'a4\'b5\'c8
\f0  
\f1 \'c8\'ad\'be\'be
\f0  
\f1 \'b0\'aa\'c0\'bb
\f0  
\f1 \'b0\'a1\'c1\'ae\'bf\'c9\'b4\'cf\'b4\'d9
\f0 .\
  float hif = dht.computeHeatIndex(f, h);\
  // 
\f1 \'ba\'b8\'c1\'a4\'b5\'c8
\f0  
\f1 \'bc\'b7\'be\'be
\f0  
\f1 \'b0\'aa\'c0\'bb
\f0  
\f1 \'b0\'a1\'c1\'ae\'bf\'c9\'b4\'cf\'b4\'d9
\f0 .\
  float hic = dht.computeHeatIndex(t, h, false);\
\
  Serial.print("Humidity: ");\
  Serial.print(h);\
  Serial.print(" %\\t");\
  Serial.print("Temperature: ");\
  Serial.print(t);\
  Serial.print(" *C ");\
  Serial.print(f);\
  Serial.print(" *F\\t");\
  Serial.print("Heat index: ");\
  Serial.print(hic);\
  Serial.print(" *C ");\
  Serial.print(hif);\
  Serial.println(" *F");\
  if(h>danger_h)\{\
    servo_1();\
    servo_5();\
    eye = 1;\
    led_1 = 1;\
  \}\
  else \{\
    eye = 0;\
    led_1 = 0;\
  \}\
 \}\
void servo_1()\{ //
\f1 \'b3\'af\'b0\'b3
\f0 \
  // rotate from 0 to 180 degrees\
 int plus=1;\
 for(angle = 0 ; angle < 90; angle+=plus) \
  \{\
    servo.write(angle);\
    servo_2.write(angle);\
    delay(13);\
    if(angle>=178)\{\
      plus*=-1;\
     \}\
    if(angle<0)\{\
       D();\
       gas_danger();\
       break;\
     \}\
  \}\
  Serial.println("
\f1 \'b3\'af\'b0\'b3
\f0  
\f1 \'c8\'ae\'c0\'ce
\f0 ");\
\}\
\
void servo_5()\{ //
\f1 \'b2\'bf\'b8\'ae
\f0 \
  // rotate from 0 to 180 degrees\
 int plus=1;\
 for(angle = 0, angle_1=180 ; angle < 180, angle_1>0; angle+=plus,angle_1-=plus) \
  \{\
    servo_3.write(angle);\
    servo_4.write(angle_1);\
    delay(13);\
    if(angle>=178)\{\
      plus*=-1;\
     \}\
    if(angle<0)\{\
    \
       break;\
     \}\
  \}\
 \
  Serial.println("
\f1 \'b2\'bf\'b8\'ae
\f0  
\f1 \'c8\'ae\'c0\'ce
\f0 ");\
\}\
\
void gas_danger()\{                    \
 Serial.println(analogRead(GasPin));  \
 delay(10);  // 10ms 
\f1 \'b4\'eb\'b1\'e2
\f0 \
 if(analogRead(GasPin)> danger_gas)\{\
     servo_1(); \
     servo_5();\
     eye = 1;\
     led_1 = 2;\
  \}\
  else\{\
    eye = 0;\
    led_1 = 0;\
   \}\
\}\
\
void eyes()\{\
 byte happy[] =\
\{\
  B00000000,\
  B00000000,\
  B00000000,\
  B01100011,\
  B00110110,\
  B00011100,\
  B00001000,\
  B00000000\
\};\
\
byte cry[] =\
\{\
  B00000000,\
  B01100110,\
  B01100110,\
  B01100110,\
  B01100110,\
  B11111111,\
  B11111111,\
  B00000000\
\};\
for (int i = 0; i < 8; i++)\{\
  if(eye == 1)\{\
    lc.setRow(0, i, cry[i]);\
    \
  \}\
  else\
    lc.setRow(0, i, happy[i]);\
  \}\
delay(3000);\
\}\
\
\
void led()\{\
  if(led_1 == 0)\{\
  for(int i=0; i<NUMPIXELS; i++)\{ // 
\f1 \'c0\'fc\'c3\'bc
\f0  LED
\f1 \'bf\'a1
\f0  
\f1 \'b4\'eb\'c7\'cf\'bf\'a9
\f0 \
    pixels.setPixelColor(i, pixels.Color(150,75,0)); // Green 
\f1 \'c4\'c3\'b7\'af
\f0 (
\f1 \'c1\'df\'b0\'a3
\f0  
\f1 \'b9\'e0\'b1\'e2
\f0 ) 
\f1 \'c1\'d8\'ba\'f1
\f0 .\
    pixels.show(); // 
\f1 \'b5\'a5\'c0\'cc\'c5\'cd
\f0  
\f1 \'c0\'fc\'bc\'db
\f0 \
  \}\
  \}\
  else if(led_1 == 1)\{\
  for(int i=0; i<NUMPIXELS; i++)\{ // 
\f1 \'c0\'fc\'c3\'bc
\f0  LED
\f1 \'bf\'a1
\f0  
\f1 \'b4\'eb\'c7\'cf\'bf\'a9
\f0 \
    pixels.setPixelColor(i, pixels.Color(0,15,240)); // Green 
\f1 \'c4\'c3\'b7\'af
\f0 (
\f1 \'c1\'df\'b0\'a3
\f0  
\f1 \'b9\'e0\'b1\'e2
\f0 ) 
\f1 \'c1\'d8\'ba\'f1
\f0 .\
    pixels.show(); // 
\f1 \'b5\'a5\'c0\'cc\'c5\'cd
\f0  
\f1 \'c0\'fc\'bc\'db
\f0 \
  \}\
  \}\
  else if(led_1 == 2)\{\
  for(int i=0; i<NUMPIXELS; i++)\{ // 
\f1 \'c0\'fc\'c3\'bc
\f0  LED
\f1 \'bf\'a1
\f0  
\f1 \'b4\'eb\'c7\'cf\'bf\'a9
\f0 \
    pixels.setPixelColor(i, pixels.Color(255,30,0)); // Green 
\f1 \'c4\'c3\'b7\'af
\f0 (
\f1 \'c1\'df\'b0\'a3
\f0  
\f1 \'b9\'e0\'b1\'e2
\f0 ) 
\f1 \'c1\'d8\'ba\'f1
\f0 .\
    pixels.show(); // 
\f1 \'b5\'a5\'c0\'cc\'c5\'cd
\f0  
\f1 \'c0\'fc\'bc\'db
\f0 \
  \}\
  \}\
\}\
\
\
void setup() \{\
  Serial.begin(9600);\
  Serial.println("DHTxx test!");\
  pinMode(GasPin ,INPUT);               // 
\f1 \'be\'c6\'b3\'af\'b7\'ce\'b1\'d7
\f0  
\f1 \'c7\'c9
\f0  A0
\f1 \'b8\'a6
\f0  
\f1 \'c0\'d4\'b7\'c2\'b8\'f0\'b5\'e5\'b7\'ce
\f0  
\f1 \'bc\'b3\'c1\'a4
\f0 \
  servo.attach(servoPin_1);\
  servo_2.attach(servoPin_2);\
  servo_3.attach(servoPin_3);\
  servo_4.attach(servoPin_4);\
  dht.begin();\
  lc.shutdown(0, false);\
  lc.setIntensity(0, 5);\
  lc.clearDisplay(0);\
  pixels.begin(); // Adafruit_Neopixel 
\f1 \'b6\'f3\'c0\'cc\'ba\'ea\'b7\'af\'b8\'ae
\f0  
\f1 \'c3\'ca\'b1\'e2\'c8\'ad
\f0 \
\}\
\
void loop() \{\
  D();\
  gas_danger();\
  eyes();\
  led();\
\}\cb1 \
\pard\pardeftab720\partightenfactor0
{\field{\*\fldinst{HYPERLINK "http://creativecommons.org/licenses/by-nc-nd/2.0/kr/"}}{\fldrslt 
\f3 \cf2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \'a0}}
\f4 \
}
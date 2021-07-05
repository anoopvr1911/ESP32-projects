#include <Arduino.h>

#define Dig1 26 //12th pin Seven segment display
#define Dig2 25 //9th pin Seven segment display
#define Dig3 33 //8th pin Seven segment display
#define Dig4 21 //6th pin Seven segment display
#define DIGIT_ON LOW
#define DIGIT_OFF HIGH
#define DISPLAY_BRIGHTNESS 5000
int i=0;
boolean duiz = false;
boolean hon = false;
#define segA 15 //11th pin of Seven segment display
#define segB 2  //7th pin of Seven segment display
#define segC 5  //4th pin of Seven segment display
#define segD 16 //2th pin of Seven segment display
#define segE 4 //1th pin of Seven segment display
#define segF 19 //10th pin of Seven segment display
#define segG 18 //5th pin of Seven segment display

void setup()
{
 pinMode(segA, OUTPUT);
 pinMode(segB, OUTPUT);
 pinMode(segC, OUTPUT);
 pinMode(segD, OUTPUT);
 pinMode(segE, OUTPUT);
 pinMode(segF, OUTPUT);
 pinMode(segG, OUTPUT);
pinMode(Dig1, OUTPUT);
pinMode(Dig2, OUTPUT);
pinMode(Dig3, OUTPUT);
pinMode(Dig4, OUTPUT);
Serial.begin(9600);
}
void lightNumber(int numberToDisplay) {
#define SEGMENT_ON HIGH
#define SEGMENT_OFF LOW
 switch (numberToDisplay){
 case 0:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_ON);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_OFF);
 break;
 case 1:
 digitalWrite(segA, SEGMENT_OFF);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_OFF);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_OFF);
 digitalWrite(segG, SEGMENT_OFF);
 break;
 case 2:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_OFF);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_ON);
 digitalWrite(segF, SEGMENT_OFF);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 3:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_OFF);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 4:
 digitalWrite(segA, SEGMENT_OFF);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_OFF);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 5:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_OFF);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 6:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_OFF);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_ON);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 7:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_OFF);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_OFF);
 digitalWrite(segG, SEGMENT_OFF);
 break;
 case 8:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_ON);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 9:
 digitalWrite(segA, SEGMENT_ON);
 digitalWrite(segB, SEGMENT_ON);
 digitalWrite(segC, SEGMENT_ON);
 digitalWrite(segD, SEGMENT_ON);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_ON);
 digitalWrite(segG, SEGMENT_ON);
 break;
 case 10:
 digitalWrite(segA, SEGMENT_OFF);
 digitalWrite(segB, SEGMENT_OFF);
 digitalWrite(segC, SEGMENT_OFF);
 digitalWrite(segD, SEGMENT_OFF);
 digitalWrite(segE, SEGMENT_OFF);
 digitalWrite(segF, SEGMENT_OFF);
 digitalWrite(segG, SEGMENT_OFF);
 break;
 }
}
void loop() {

 duiz = false;
 hon = false;
 if(touchRead(32)<20)

  {i++;
  }

 
 for(int k = 0; k<50; k++){ // for loop to slow it down.

 int figur = i;
 for(int digit = 1 ; digit < 5 ; digit++) { //for loop to place the number in the right digit
 switch(digit) {
 case 1:
 if(figur > 999){
 digitalWrite(Dig1, DIGIT_ON);
 lightNumber(figur / 1000); // for example 2511 / 1000 = 2
 figur %= 1000; // new value of figur = 511 figur = figur %1000

 delayMicroseconds(DISPLAY_BRIGHTNESS);
 if (figur < 100){
 duiz = true;
 if (figur <10){
 hon = true;

 }

 }else duiz = false;
 }

 break;
 case 2:
 if(duiz == true){
 digitalWrite(Dig2, DIGIT_ON);
 lightNumber(0);
 delayMicroseconds(DISPLAY_BRIGHTNESS);

 }if(hon == true){
 break;
 }

 if(figur > 99 && figur < 1000){
 digitalWrite(Dig2, DIGIT_ON);
 lightNumber(figur / 100);
 figur %= 100;
 delayMicroseconds(DISPLAY_BRIGHTNESS);
 if (figur < 10){
 hon = true;

 }else hon = false;
 }
 break;
 case 3:
 if(hon == true){
 digitalWrite(Dig3, DIGIT_ON);
 lightNumber(0);
 delayMicroseconds(DISPLAY_BRIGHTNESS);
 break;
 }

 if(figur > 9 && figur < 100){
 digitalWrite(Dig3, DIGIT_ON);
 lightNumber(figur / 10);
 figur %= 10;
 delayMicroseconds(DISPLAY_BRIGHTNESS);
 }

 break;
 case 4:
 if(figur < 10){
 digitalWrite(Dig4, DIGIT_ON);
 lightNumber(figur);
 delayMicroseconds(DISPLAY_BRIGHTNESS);

 break;
 }
 }
 //Turn off all segments
 lightNumber(10);
 //Turn off all digits
 digitalWrite(Dig1, DIGIT_OFF);
 digitalWrite(Dig2, DIGIT_OFF);
 digitalWrite(Dig3, DIGIT_OFF);
 digitalWrite(Dig4, DIGIT_OFF);

}
} 
}

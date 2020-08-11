#include <ESP8266WiFi.h>
#define EN1 D6 // Enable PIN to control speed
#define EN2 D7
int x=0;
long duration=0;
const int trigP = D1; //D4
const int echoP = D2; //D3

int LS=0;
int RS=0;
void setup() {
 Serial.begin(115200);
 pinMode(EN1, OUTPUT);
 pinMode(EN2,OUTPUT);
 pinMode(trigP, OUTPUT); // Sets the trigPin as an Output
pinMode(echoP, INPUT);
 // Connect to WiFi network

}
void loop() {
 digitalWrite(trigP, LOW); // Makes trigPin low
delayMicroseconds(2); // 2 micro second delay
digitalWrite(trigP, HIGH); // tigPin high
delayMicroseconds(10); // trigPin high for 10 micro
digitalWrite(trigP, LOW);
duration = pulseIn(echoP, HIGH); //Read echo pin, time in

x= duration*0.034/2;
if(x>100)
{
  LS=1000;
  RS=1000; 
}
 else
 {
 LS=1.33640679 -2.98198383*x+2.65239419*x*x-0.48317624*x*x*x +100;//w0,w1,w2 for left
 RS=0.96151784-0.44010795*x+0.48240533*x*x-0.93225746*x*x*x+100;//w0,w1,w2 for right
 }
 LS=LS-(LS%100);
 RS=RS-(RS%100);
 analogWrite(EN1,LS);
 analogWrite(EN2,RS);
 
 
}

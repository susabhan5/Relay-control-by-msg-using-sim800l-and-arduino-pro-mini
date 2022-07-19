#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TXchar data;
#define Bulb1 A0
char data;
String buff;
String buf;
 //char buf[30];
 void setup()  
 {
   Serial.begin(9600);
   mySerial.begin(9600);
   delay(1000);
    pinMode(Bulb1, OUTPUT);
    digitalWrite(Bulb1,HIGH);

     mySerial.println("AT+CNMI=2,2,0,0,0");  
 delay(500);
 Serial.println("Begin serial communication with (SIM800L)");
    mySerial.println("AT");// send AT
  delay(500);
 // mySerial.write("AT+IPR=9600\r");
 // delay(500);  
 mySerial.println("AT+CMGF=1");  
 delay(500);
  mySerial.println("AT+DDET=1"); //Enable DTMF
  delay(500);
  mySerial.write("AT+CLIP=0"); //Enable Caller ID
  delay(500);
  while(mySerial.available()){
  buff = mySerial.readString();
 Serial.println(buff);
 delay(500);
 buff = "";
 delay(200);   
 }
 } 

 void loop()  
 {
 Serial.println(" *" ) ;
while(mySerial.available())
{  
SerialEvent();
delay(200);
}
}

 void SerialEvent()  
 {
  Serial.println(" check point - 4* " ) ; 
 while(mySerial.available()){
 buff= mySerial.readString();
Serial.println(buff);
delay(200);
Serial.println("buff");
  String buf = buff.substring(52);
Serial.println(buf);
 buff = "";
 delay(200);
 buf = "";
 delay(200);
 }
 }

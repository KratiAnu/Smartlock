#include<SoftwareSerial.h>

#include<Servo.h>
Servo myservo;

int TxD = 10;
int RxD = 11;

SoftwareSerial bluetooth(TxD, RxD);


void setup() {
  myservo.attach(9);
Serial.begin(9600);
bluetooth.begin(9600);
}

void loop() 
{
  if(bluetooth.available()> 0 )
  {
    int servopos = bluetooth.read(); 
    Serial.println(servopos);
    myservo.write(servopos); // rotate the servo the angle received from the android app
  }

}

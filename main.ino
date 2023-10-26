/* 
 * Created by: Mikey Gloriani
 * Created on: Oct 2023
 *
 * If the distance is less than 50 cm, the servo will move
 */
#include <Servo.h>

Servo servoNumber1;

const int trigPin = 10;
const int echoPin = 9;
float duration, distance;

void setup() {
    //sets up sensor pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    
    //sets up the servo pins
    servoNumber1.attach(5);
    servoNumber1.write(0);
}

void loop() {
    //Sends out a sonic burst
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Calculates and prints the distance onto the Serial Monitor 
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
  
   if (distance < 50) {
     //servo will move 180 and back
     servoNumber1.write(0);
     delay(1000);
     servoNumber1.write(180);
     delay(1000);
  }
  else {
     //servo does not move
     servoNumber1.write(0);
     delay(1000);
  }
}

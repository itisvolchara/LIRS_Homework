#include <Servo.h>

const int SERVO_PIN1 = 7;
const int SERVO_PIN2 = 8;

int first_angle;
int second_angle;
int index;

String input;

Servo servo[2];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  servo[0].attach(SERVO_PIN1);
  servo[1].attach(SERVO_PIN2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    input = Serial.readString();
    index = input.indexOf(' ');

    first_angle = input.substring(0, index).toInt();
    second_angle = input.substring(index).toInt();
    
    servo[0].write(first_angle);
    servo[1].write(second_angle);
  }
}
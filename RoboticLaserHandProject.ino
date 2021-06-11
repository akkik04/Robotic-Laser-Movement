#include <Servo.h>

// instantiating the servo motor.
Servo myservo;

// declaring variables for pin numbers.
const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;
const int Laser_pin = 12;

void setup() {
  
  // attaching the servo motor to pin 10.
  myservo.attach(10);
  
  // initializing the switch pin as input.
  pinMode(SW_pin, INPUT);

  // initializing the serial monitor.
  Serial.begin(9600);

  // originally initializing the switch pin to 1.
  digitalWrite(SW_pin, HIGH);

  // declaring the laser pin as output.
  pinMode(Laser_pin, OUTPUT);

  }
  
  // declaring the servo's initial position as 90 degrees.
  int servopos1 = 90;

// MAIN-LOOP.
void loop() {

  // reading the x and y coordinates of the joystick.
  int x_cor = analogRead(X_pin);
  int y_cor = analogRead(Y_pin);
  int angle1, angle2;
  
  // creating an if-statement to check for movement from the joystick.
  if (x_cor <= 450 or x_cor >= 550){
  
    // if the joystick is moved, mapping the angle to the x-coordinate.
    angle1 = map(x_cor, 0, 1023, -30, 30);
    servopos1 = servopos1 + angle1;
    
    // stopping the movement of the servo motor with the laser if the position is 180 or 0.
    if (servopos1 > 180) servopos1 = 180;
    if (servopos1 < 0) servopos1 = 0;
  }
  
  // if-statement that does the same job as the previous one. 
  // **I'LL BE MAKING CHANGES TO THIS IF-STATEMENT IN THE NEXT WORKING ROUND."
  if (y_cor <= 450 or y_cor >= 550){

    angle2 = map(y_cor, 0, 1023, -30, 30);
    servopos1 = servopos1 + angle2;

    if (servopos1 > 180) servopos1 = 180;
    if (servopos1 < 0) servopos1 = 0;
  }
  
  // writing the position to move to.
  myservo.write(servopos1);
  
  // creating an if-statement to shine the laser when the joystick is pressed.
  if (digitalRead(SW_pin) == LOW){

    digitalWrite(Laser_pin, HIGH);
  }
  
  else {

    digitalWrite(Laser_pin, LOW);
    delay(500);
  }
 
}

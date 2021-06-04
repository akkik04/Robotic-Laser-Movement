// declaring variables for pin numbers.
const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;
const int Laser_pin = 12;

void setup() {
  
  // initializing the switch pin as input.
  pinMode(SW_pin, INPUT);

  // initializing the serial monitor.
  Serial.begin(9600);

  // originally initializing the switch pin to 1.
  digitalWrite(SW_pin, HIGH);

  // declaring the laser pin as output.
  pinMode(Laser_pin, OUTPUT);

  }

// MAIN-LOOP.
void loop() {

  // if-statement to determine when the laser should light up.
   if (digitalRead(SW_pin) == LOW){

    digitalWrite(Laser_pin, HIGH);
  }
  else{

    digitalWrite(Laser_pin, LOW);
  }

  delay(1000);
 
}

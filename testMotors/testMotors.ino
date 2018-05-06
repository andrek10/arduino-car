const int dir2PinB = 8; //Black
const int dir1PinB = 7; //Green
const int speedPinA = 4; //Purple
const int speedPinB = 9; //Yellow
const int dir2PinA = 6; //Orange
const int dir1PinA = 5; //Red


void setup()
{
  Serial.begin(9600);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

  // Run through all configs, check with serial output what is happening

  // Forward left wheel
  Serial.println("Forward left wheel in 500ms:");
  delay(500);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  analogWrite(speedPinA, 200);
  delay(2000);
  // Stop
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinA, 0);

  // Backward left wheel
  Serial.println("Backward left wheel in 500ms:");
  delay(500);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinA, 200);
  delay(2000);
  // Stop
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinA, 0);

  // Forward left wheel
  Serial.println("Forward right wheel in 500ms:");
  delay(500);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  analogWrite(speedPinB, 200);
  delay(2000);
  // Stop
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinB, 0);

  // Backward right wheel
  Serial.println("Backward right wheel in 500ms:");
  delay(500);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinB, 200);
  delay(2000);
  // Stop
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinB, 0);

  Serial.println("Finished");
}

void loop()
{
  
}

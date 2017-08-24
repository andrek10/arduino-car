const int dummy = 0;
const int irpin = 11; //Green
const int dir2PinB = 8; //Black
const int dir1PinB = 7; //Green
const int speedPinA = 6; //Purple
const int speedPinB = 5; //Yellow
const int dir2PinA = 4; //Orange
const int dir1PinA = 2; //Red


void setup()
{
  Serial.begin(9600);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
}

void loop()
{
  Serial.print("hei");
  /*
  //Forward left wheel
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  analogWrite(speedPinA, 200);
  */
  
  /*
  //Backward left wheel
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinA, 200);
  */
  
  /*
  //Forward right wheel
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  analogWrite(speedPinB, 200);
  */
  
  /*
  //Backward right wheel
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  analogWrite(speedPinB, 200);
  */
}

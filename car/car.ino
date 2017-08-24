const int dummy = 0;
const int irpin = 11; //Green
const int in4pin = 8; //Black
const int in3pin = 7; //Green
const int enApin = 6; //Purple
const int enBpin = 5; //Yellow
const int in2pin = 4; //Orange
const int in1pin = 2; //Red


void setup()
{
  Serial.begin(9600);
  pinMode(enApin, OUTPUT);
  pinMode(enBpin, OUTPUT);
  digitalWrite(enApin, HIGH);
  digitalWrite(enBpin, LOW);
}

void loop()
{
  Serial.print("hei");
}

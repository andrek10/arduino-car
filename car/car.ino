/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino Uno board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

/*

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

*/

// Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

// Define my own variables
// -----------------------
// Motor on/off
int motorOn;
// Joystick position
int x1=0, y1=0, x2=0, y2=0;
float xf1=0, yf1=0, xf2=0, yf2=0;
// Motor speed
float motorSpeed=0.0;
// Direction
float carDirection=0.0;

// Motor pins
const int dir2PinB = 8; //Black
const int dir1PinB = 7; //Green
const int speedPinA = 4; //Purple
const int speedPinB = 9; //Yellow
const int dir2PinA = 6; //Orange
const int dir1PinA = 5; //Red

// Direction Joystick (left)
BLYNK_WRITE(V1) {
  x1 = param[0].asInt();
  y1 = param[1].asInt();
  xf1 = float(x1);
  yf1 = float(y1);

  // Get direction
  carDirection = xf1/128.0;
}

// Speed Joystick (right)
BLYNK_WRITE(V2) {
  x2 = param[0].asInt();
  y2 = param[1].asInt();
  xf2 = float(x2);
  yf2 = float(y2);

  // Calculate motor speed
  motorSpeed = yf2/128.0;
}

// Motor on/off
BLYNK_WRITE(V8) {
  motorOn = param.asInt();
  Serial.print("motorOn = ");
  Serial.println(motorOn);
}

void motorParameters(float motorSpeed, float carDirection){
  // motorSpeed <-1.0, +1.0>
  // carDirection <-1.0, +1.0>,   +1.0 = Turn Right  
  if (motorSpeed >= 0.0) {
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
  } else {
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
  }
  if (carDirection >= 0.0) {
    analogWrite(speedPinA, int(abs(motorSpeed*255.0)));
    Serial.println(abs(motorSpeed*255.0));
    analogWrite(speedPinB, int(abs(motorSpeed*255.0) - abs(carDirection*128.0)));
  } else {
    analogWrite(speedPinA, int(abs(motorSpeed*255.0) - abs(carDirection*128.0)));
    analogWrite(speedPinB, int(abs(motorSpeed*255.0)));
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Set internal blinklight
  pinMode(LED_BUILTIN, OUTPUT);

  // Motor pins
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

  // Change car speed and direction
  if (motorOn == 1) {
    motorParameters(motorSpeed, carDirection);
  }
  else {
    motorParameters(0.0, 0.0);
  }
}


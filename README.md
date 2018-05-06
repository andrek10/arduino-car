# arduino-car
## Arduino Programs
### blynkTest
blynkTest is used to check if ESP8266 is configured correctly to support Blynk.
Blynk libraries must be located in the sketch-folder.
Add auth-token and WiFi SSID and Password to function properly.
ESP8266 is set to BAUD rate 9600 using the command
AT+UART_DEF=9600,8,1,0,0
### car
The arduino program to run the car.
Blynk libraries must be located in the sketch-folder.
Add auth-token and WiFi SSID and Password to function properly.
## Wire Connections
### Motor shield <-> Arduino
ENA - D4
IN1 - D5
IN2 - D6
IN3 - D7
IN4 - D8
ENB - D9

### Motor shield <-> Power
VCC - 6V Batteries
GND - GND

### ESP8266 Wifi Shield <-> Arduino
TX - D2
RX - D3

### ESP8266 Wifi Shield <-> Power
VCC - 3V3
GND - GND
CH_PD - 3V3

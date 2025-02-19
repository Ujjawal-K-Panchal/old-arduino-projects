//Tempaerature Sensor
#include<SoftwareSerial.h>
SoftwareSerial LCD(2,3);//RX TX
int TempPin=A0;
float temp;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   LCD.begin(9600);
   clearScreen();
}
void loop() {
  clearScreen();
  // put your main code here, to run repeatedly:
    temp=analogRead(TempPin);
    temp*=0.49;
    Serial.print("Temperature is:");
    Serial.print(temp);
    Serial.print("°C");
    LCD.print("Temperature is:")
    setLCDCursor(20);
    LCD.print(temp);
    LCD.print((char)223);
    LCD.print("C");
    delay(1000);
}
void clearScreen()
{
  //clears the screen, you will use this a lot!
  LCD.write(0xFE);
  LCD.write(0x01); 
}
void setLCDCursor(byte cursor_position)
{
  LCD.write(0xFE);  // send the special command
  LCD.write(0x80);  // send the set cursor command
  LCD.write(cursor_position);  // send the cursor position
}

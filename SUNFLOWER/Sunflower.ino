#include <Servo.h>      //including the library of servo motor 
Servo sg90;                   //initializing a variable for servo named sg90
int initial_position = 90;    //Declaring the initial position at 90
int LDR1 = A0;                //Pin at which LDR is connected
int LDR2 = A1;                //Pin at which LDR is connected
int error = 500;                //initializing variable for error
int servopin=9;
void setup() 
{ 
  Serial.begin(9600);
  sg90.attach(servopin);  // attaches the servo on pin 9
  pinMode(LDR1, INPUT);   //Making the LDR pin as input
  pinMode(LDR2, INPUT);
  sg90.write(initial_position);   //Move servo at 90 degree
  delay(20);                   // giving a delay of 2 seconds
}
void loop() 
{ 
  int R1 = analogRead(LDR1); // reading value from LDR 1
  int R2 = analogRead(LDR2); // reading value from LDR 2
  
  int diff1= abs(R1 - R2);   // Calculating the difference between the LDR's 
  Serial.println(R1);
  Serial.println(R2);
  Serial.println(diff1);
  Serial.println();Serial.println();Serial.println();
  if((diff1 <= error)) {
    //if the difference is under the error then do nothing
  } 
  else {    
    if(R1 > R2)
    {
      initial_position -= 20;  //Move the servo towards 0 degree
      sg90.write(initial_position);
    }
    if(R1 < R2) 
    {
      initial_position += 20; //Move the servo towards 180 degree
      sg90.write(initial_position);
    }
  }
  delay(500);
}

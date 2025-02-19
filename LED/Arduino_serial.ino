int redLEDPin=9; //Declare redLEDPin an int, and set to pin 9 
int yellowLEDPin=10; //Declare yellowLEDPin an int, and set to pin 10 
int redOnTime=125; //Declare redOnTime an int, and set to 250 mseconds 
int redOffTime=125; //Declare redOffTime an int, and set to 250 
int yellowOnTime=125; //Declare yellowOnTime an int, and set to 250
int yellowOffTime=125; //Declare yellowOffTime an int, and set to 250
int numYellowBlinks; //Number of times to blink yellow LED
int numRedBlinks;  //Number of times to blink red LED

void setup() {
  Serial.begin(115200);
  Serial.print("How many blinks for Red LED?:>");
  while(!Serial.available());
  numRedBlinks=Serial.parseInt();
  Serial.println();
  Serial.print("How many blinks for Yellow LED?:>");
  while(!Serial.available());
  numYellowBlinks=Serial.parseInt();
  pinMode(redLEDPin, OUTPUT);  // Tell Arduino that redLEDPin is an output pin
  pinMode(yellowLEDPin, OUTPUT);  //Tell Arduino that yellowLEDPin is an output pin
}

void loop() {
  
Serial.println("The Red LED is Blinking");
  for (int j=1; j<=numRedBlinks; j=j+1) {     // Start our for loop
    Serial.print("   You are on Blink #: ");
    Serial.println(j);
    digitalWrite(redLEDPin,HIGH); //Turn red LED on
    delay(redOnTime);             //Leave on for redOnTime
    digitalWrite(redLEDPin,LOW);  //Turn red LED off
    delay(redOffTime);            //Leave off for redOffTime
}
Serial.println(" ");
Serial.println("The Yellow Yellow is Blinking");
  for (int j=1; j<=numYellowBlinks; j=j+1) {     // Start our for loop
    Serial.print("   You are on Blink #: ");
    Serial.println(j);
    digitalWrite(yellowLEDPin,HIGH); //Turn yellow LED on
    delay(yellowOnTime);             //Leave on for yellowOnTime
    digitalWrite(yellowLEDPin,LOW);  //Turn yellow LED off
    delay(yellowOffTime);            //Leave off for yellowOffTime
}
Serial.println(" ");
}

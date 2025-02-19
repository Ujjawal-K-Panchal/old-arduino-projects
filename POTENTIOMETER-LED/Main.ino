int LEDpin=9;
int POTpin=A0;
float readvalue;
float writevalue;

void setup() {
                pinMode(9,OUTPUT);
                pinMode(POTpin,INPUT);
}

void loop() {
              readvalue=analogRead(POTpin);
              writevalue=readvalue/204.6;
              analogWrite(LEDpin,writevalue);             
}

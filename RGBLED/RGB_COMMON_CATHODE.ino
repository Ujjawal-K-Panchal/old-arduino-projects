int redPin=11;
int greenPin=10;
int bluePin=6;
int brightness=15;

void setup() {
                Serial.begin(9600);
                pinMode(redPin,OUTPUT);   
                pinMode(greenPin,OUTPUT);
                pinMode(bluePin,OUTPUT);
                
}

void loop() {
              analogWrite(redPin,brightness+100);
              analogWrite(greenPin,brightness);
              analogWrite(bluePin,brightness);

}



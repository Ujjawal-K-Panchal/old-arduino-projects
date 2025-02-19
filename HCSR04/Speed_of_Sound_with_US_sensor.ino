int trigPin=13;
int echo=11;
float pingtime;
int echoPin=11;
float sndspeed=343;
float dst;
int buzzer=8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT); 
   
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigPin,LOW);
 delayMicroseconds(10);

 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);//Pause with trigger pin high.
 digitalWrite(trigPin,LOW);
 pingtime=pulseIn(echoPin,HIGH);
 Serial.print("time:");
 Serial.println(pingtime);
 dst=(sndspeed*pingtime)/20000;

 Serial.print("Distance:");Serial.println(dst);
                 if(dst<60){
                            digitalWrite(buzzer,HIGH);
                            delay(5000);
                            digitalWrite(buzzer,LOW);     
                 }
 delay(1);
 
}

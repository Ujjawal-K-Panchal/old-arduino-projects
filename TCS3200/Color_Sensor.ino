unsigned int pulsewidth;
int redpart, greenpart , bluepart;
int S2=7;
int S3=8;
int outpin=4;
void setup() {
  Serial.begin(9600);
  pinMode(outpin,INPUT);
}

void loop() {
  //Reading the red component(S2 LOW ,S3 LOW)
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  pulsewidth = pulseIn(outpin,LOW);
  redpart=pulsewidth/401;
  //Reading the green component(S2 LOW, S3 HIGH)
  digitalWrite(S3,HIGH);
  pulsewidth= pulseIn(outpin,LOW);
  greenpart=pulsewidth/401;
  //Reading the blue component(S2,HIGH, S3 HIGH)
  digitalWrite(S2,HIGH);
  pulsewidth=pulseIn(outpin,LOW);
  bluepart=pulsewidth/400;
  Serial.print("The Red component of color is:>");Serial.println(redpart);
  Serial.print("The Green component of the color is:>");Serial.println(greenpart);
  Serial.print("The Blue component of the color is:>");Serial.println(bluepart);
   
  delay(1000);
}

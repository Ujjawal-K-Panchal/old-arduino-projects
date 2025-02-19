#include <SoftwareSerial.h>
#include <Key.h>
#include <Keypad.h>

SoftwareSerial LCD(1,3);//RX  , TX.

int trigPin=12;
int echo=11;
float pingtime;
int echoPin=11;
float sndspeed=343;
float dst;
int buzzer=13;
int i=0;char pass[16];
char key;
const byte rows=4;
const byte cols=4;

char keys[rows][cols]=//defining what each element is.
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//Telling which pins they're connected to.
byte rowPins[rows]={10,9,8,7};
byte colPins[cols]={6,5,4,2};
//defining the keypad object with above info.
Keypad keypad= Keypad(makeKeymap(keys),rowPins,colPins,rows,cols);//As defined above.
char password[16]="007*";
int compare;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
                     pinMode(trigPin,OUTPUT);
                    pinMode(echoPin,INPUT);
                    pinMode(buzzer,OUTPUT); 
                    Serial.begin(9600);
                    LCD.begin(9600);
                    clearScreen();
                    LCD.print("Calibrating!");delay(1000);
                                                          
                                                          
                                                          
}

void loop() {
  // put your main code here, to run repeatedly:
  compare=0;int done=0;
    clearScreen();
              LCD.print("Enter password:>");
                    setLCDCursor(20);
          do{          
              key = keypad.getKey();
              if(key!=0 && i<=15){
                                      pass[i]=key;i++;               
                                    LCD.print("*");
                                 }
                        
                        if(key=='*' || i==15)
                        { 
                          Serial.println();
                           compare=passCmp(password,pass);
                           switch(compare){
                                            case 1:clearScreen();LCD.print("Correct Password!"); break;//to be programmed
                                            case 0:clearScreen();LCD.print("Incorrect Password!");break;//to be programmed  
                                          }
                                        i=0;
                                        done=1;
                        }
                                   digitalWrite(trigPin,HIGH);
                                   delayMicroseconds(10);//Pause with trigger pin high.
                                   digitalWrite(trigPin,LOW);
                                   pingtime=pulseIn(echoPin,HIGH);
                                   dst=(sndspeed*pingtime)/20000;
                                   Serial.print(dst);delay(5);
                                                  if(compare==1){
                                                    delay(5000);
                                                  }
                                                  else if(dst<60)
                                                   {
                                                     digitalWrite(buzzer,HIGH);
                                                     delay(5000);
                                                     digitalWrite(buzzer,LOW);
                                                   }
             }while(!done);
                 
}
int passCmp(char str1[], char str2[]){
                            int j=0;int counter=1;
                            
                            for(int j=0;(str1[j]!='*' && j<=15);j++)
                               {
                                
                                  if(!(str1[j]==str2[j])){
                                    counter=0;break;
                                  }
                               }
                               
                               return counter;
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

#include <Key.h>
#include <Keypad.h>

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
byte rowPins[rows]={11,10,9,8};
byte colPins[cols]={7,6,5,4};
//defining the keypad object with above info.
Keypad keypad= Keypad(makeKeymap(keys),rowPins,colPins,rows,cols);//As defined above.
char password[16]="007*";
int compare;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("You typed:");
}

void loop() {
  // put your main code here, to run repeatedly:
              key = keypad.getKey();
              if(key!=0 && i<=15){
                    
                                  pass[i]=key;i++;  
                               
                                Serial.print(pass[i-1]);
                    
                        }
                        
                        if(key=='*' || i==15)
                        {
                          Serial.println();
                           compare=passCmp(password,pass);
                           switch(compare){
                                            case 1: Serial.print("CORRECT!");break;
                                            case 0: Serial.print("INCORRECT!");break;  
                                         }
                                        i=0;
                        }
                        
             
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


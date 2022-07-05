#include "pitches.h"
#define ACTIVATED LOW
/*
NOTE_C4, //DO 0
NOTE_D4, //RE 1
NOTE_E4, //MI 2
NOTE_F4, //FA 3
NOTE_G4, //SOL 4
NOTE_A4, //LA 5
NOTE_B4, //SI 6
NOTE_C5, // DO 7
  */
const int BOTON_C4 = 3; //DO 0-->262
const int BOTON_D4 = 4; //RE 1-->294
const int BOTON_E4 = 5; //MI 2-->330
const int BOTON_F4 = 6; //FA 3-->349
const int BOTON_G4 = 7; //SOL 4-->392 
const int BOTON_A4 = 8; //LA 5-->440 
const int BOTON_B4 = 9; //SI 6--> 494
const int BOTON_C5 = 10; //DO 7--> 523

int frequency[] = {262, 294, 330, 349, 392, 440, 494, 523};
int val=0;
unsigned long on_time=0;
unsigned long off_time=0;
unsigned long button_ontime[100];
unsigned long button_offtime[100];
int button_seq[100];

int buttonPin = 2;
int previousState = HIGH;
unsigned int previousPress;
volatile int buttonFlag;
int buttonDebounce = 200;
int BOTON;

int path=1;
int i=0;
int f=0;
void playback (void);
void GRABAR_NOTA(void);


void setup() 
{
Serial.begin(9600);

pinMode(buzzer,OUTPUT);

pinMode(BOTON_C4,INPUT_PULLUP);
pinMode(BOTON_D4,INPUT_PULLUP);
pinMode(BOTON_E4,INPUT_PULLUP);
pinMode(BOTON_F4,INPUT_PULLUP);
pinMode(BOTON_G4,INPUT_PULLUP);
pinMode(BOTON_A4,INPUT_PULLUP);
pinMode(BOTON_B4,INPUT_PULLUP);
pinMode(BOTON_C5,INPUT_PULLUP);
pinMode(buttonPin,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2), button_ISR, CHANGE);

analogWrite(buzzer,0);

}

void loop() 
{
if(path==0)
{
  Serial.println("playback");
  playback();
}
if((millis() - previousPress) > buttonDebounce && buttonFlag)
  {
    previousPress = millis();
    if(digitalRead(buttonPin) == LOW && previousState == HIGH)
    {
      path =! path;
      previousState = LOW;
    }
    
    else if(digitalRead(buttonPin) == HIGH && previousState == LOW)
    {
      previousState = HIGH;
    }
    buttonFlag = 0;
  }

if(digitalRead(BOTON_C4)==LOW)
{ 
  tone(buzzer,frequency[0]);
  BOTON = BOTON_C4;
  GRABAR_NOTA();
}

else if(digitalRead(BOTON_D4)==LOW)
{
tone(buzzer,frequency[1]);
BOTON = BOTON_D4;
f=1;
GRABAR_NOTA();
}

else if(digitalRead(BOTON_E4)==LOW)
{
tone(buzzer,frequency[2]);
BOTON = BOTON_E4;
f=2;
GRABAR_NOTA();
}

else if(digitalRead(BOTON_F4)==LOW)
{
tone(buzzer,frequency[3]);
BOTON = BOTON_F4;
f=3;
GRABAR_NOTA();
}

else if(digitalRead(BOTON_G4)==LOW)
{
tone(buzzer,frequency[4]);
BOTON = BOTON_G4;
f=4;
GRABAR_NOTA();
}

else if(digitalRead(BOTON_A4)==LOW)
{
tone(buzzer,frequency[5]);
BOTON = BOTON_A4;
f=5;
GRABAR_NOTA();
}

else if(digitalRead(BOTON_B4)==LOW)
{
tone(buzzer,frequency[6]);
BOTON = BOTON_B4;
f=6;
GRABAR_NOTA();
}
else if(digitalRead(BOTON_C5)==LOW)
{
tone(buzzer,frequency[7]);
BOTON = BOTON_C5;
f=7;
GRABAR_NOTA();
}
noTone(buzzer);
}


void playback (void)
{

 for(int j=0;j<i;j++)
 {
  tone(buzzer,frequency[button_seq[j]]);
  delay(button_ontime[j]);
  noTone(buzzer);
  delay(button_offtime[j]);
 }
 i=0;
 off_time=0;
 on_time=0;
 path=1;

}

void GRABAR_NOTA (void)
{
  on_time=millis();
  if(i!=0)
  {
    button_offtime[i-1]=on_time-off_time;
  }
  while(digitalRead(BOTON)==LOW);
  if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=f;
    i++;
  }
}

void button_ISR()
{
  buttonFlag = 1;
}

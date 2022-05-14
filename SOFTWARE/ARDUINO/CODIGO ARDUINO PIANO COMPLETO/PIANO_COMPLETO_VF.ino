#include "pitches.h"
const int buzzer = 13;

#define NOTA_B0  31
#define NOTA_C1  33
#define NOTA_CS1 35
#define NOTA_D1  37
#define NOTA_DS1 39
#define NOTA_E1  41
#define NOTA_F1  44
#define NOTA_FS1 46
#define NOTA_G1  49
#define NOTA_GS1 52
#define NOTA_A1  55
#define NOTA_AS1 58
#define NOTA_B1  62
#define NOTA_C2  65
#define NOTA_CS2 69
#define NOTA_D2  73
#define NOTA_DS2 78
#define NOTA_E2  82
#define NOTA_F2  87
#define NOTA_FS2 93
#define NOTA_G2  98
#define NOTA_GS2 104
#define NOTA_A2  110
#define NOTA_AS2 117
#define NOTA_B2  123
#define NOTA_C3  131
#define NOTA_CS3 139
#define NOTA_D3  147
#define NOTA_DS3 156
#define NOTA_E3  165
#define NOTA_F3  175
#define NOTA_FS3 185
#define NOTA_G3  196
#define NOTA_GS3 208
#define NOTA_A3  220
#define NOTA_AS3 233
#define NOTA_B3  247
#define NOTA_C4  262
#define NOTA_CS4 277
#define NOTA_D4  294
#define NOTA_DS4 311
#define NOTA_E4  330
#define NOTA_F4  349
#define NOTA_FS4 370
#define NOTA_G4  392
#define NOTA_GS4 415
#define NOTA_A4  440
#define NOTA_AS4 466
#define NOTA_B4  494
#define NOTA_C5  523
#define NOTA_CS5 554
#define NOTA_D5  587
#define NOTA_DS5 622
#define NOTA_E5  659
#define NOTA_F5  698
#define NOTA_FS5 740
#define NOTA_G5  784
#define NOTA_GS5 831
#define NOTA_A5  880
#define NOTA_AS5 932
#define NOTA_B5  988
#define NOTA_C6  1047
#define NOTA_CS6 1109
#define NOTA_D6  1175
#define NOTA_DS6 1245
#define NOTA_E6  1319
#define NOTA_F6  1397
#define NOTA_FS6 1480
#define NOTA_G6  1568
#define NOTA_GS6 1661
#define NOTA_A6  1760
#define NOTA_AS6 1865
#define NOTA_B6  1976
#define NOTA_C7  2093
#define NOTA_CS7 2217
#define NOTA_D7  2349
#define NOTA_DS7 2489
#define NOTA_E7  2637
#define NOTA_F7  2794
#define NOTA_FS7 2960
#define NOTA_G7  3136
#define NOTA_GS7 3322
#define NOTA_A7  3520
#define NOTA_AS7 3729
#define NOTA_B7  3951
#define NOTA_C8  4186
#define NOTA_CS8 4435
#define NOTA_D8  4699
#define NOTA_DS8 4978

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
const int BOTON_C4 = 3; //DO 1
const int BOTON_D4 = 4; //RE 2
const int BOTON_E4 = 5; //MI 3
const int BOTON_F4 = 6; //FA 4
const int BOTON_G4 = 7; //SOL 5
const int BOTON_A4 = 8; //LA 6
const int BOTON_B4 = 9; //SI 7
const int BOTON_C5 = 10; //DO 8

int frequency[] = {262, 294, 330, 349, 392, 440, 494, 523};

int val=0;
unsigned long on_time=0;
unsigned long off_time=0;
unsigned long button_ontime[200];
unsigned long button_offtime[200];
int button_seq[200];

int buttonPin = 2;
int previousState = HIGH;
unsigned int previousPress;
volatile int buttonFlag;
int buttonDebounce = 200;

int path=1;
int i=0;


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

void button_ISR()
{
  buttonFlag = 1;
  
}

void Play_Piratas()
{ 
  const float velocidadcancion = 1;
  int notas[] = {
    NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0,
    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
    NOTA_A4, NOTA_G4, NOTA_A4, 0,

    NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0,
    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
    NOTA_A4, NOTA_G4, NOTA_A4, 0,

    NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0,
    NOTA_A4, NOTA_C5, NOTA_D5, NOTA_D5, 0,
    NOTA_D5, NOTA_E5, NOTA_F5, NOTA_F5, 0,
    NOTA_E5, NOTA_D5, NOTA_E5, NOTA_A4, 0,

    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_D5, NOTA_E5, NOTA_A4, 0,
    NOTA_A4, NOTA_C5, NOTA_B4, NOTA_B4, 0,
    NOTA_C5, NOTA_A4, NOTA_B4, 0,

    NOTA_A4, NOTA_A4,
    
    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
    NOTA_A4, NOTA_G4, NOTA_A4, 0,

    NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0,
    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_C5, NOTA_D5, NOTA_B4, NOTA_B4, 0,
    NOTA_A4, NOTA_G4, NOTA_A4, 0,

    NOTA_E4, NOTA_G4, NOTA_A4, NOTA_A4, 0,
    NOTA_A4, NOTA_C5, NOTA_D5, NOTA_D5, 0,
    NOTA_D5, NOTA_E5, NOTA_F5, NOTA_F5, 0,
    NOTA_E5, NOTA_D5, NOTA_E5, NOTA_A4, 0,

    NOTA_A4, NOTA_B4, NOTA_C5, NOTA_C5, 0,
    NOTA_D5, NOTA_E5, NOTA_A4, 0,
    NOTA_A4, NOTA_C5, NOTA_B4, NOTA_B4, 0,
    NOTA_C5, NOTA_A4, NOTA_B4, 0,
    

    NOTA_E5, 0, 0, NOTA_F5, 0, 0,
    NOTA_E5, NOTA_E5, 0, NOTA_G5, 0, NOTA_E5, NOTA_D5, 0, 0,
    NOTA_D5, 0, 0, NOTA_C5, 0, 0,
    NOTA_B4, NOTA_C5, 0, NOTA_B4, 0, NOTA_A4,

    NOTA_E5, 0, 0, NOTA_F5, 0, 0,
    NOTA_E5, NOTA_E5, 0, NOTA_G5, 0, NOTA_E5, NOTA_D5, 0, 0,
    NOTA_D5, 0, 0, NOTA_C5, 0, 0,
    NOTA_B4, NOTA_C5, 0, NOTA_B4, 0, NOTA_A4};
    int duracion[] = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,

    250, 125,
 
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,


    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500,

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500};
    const int totalNotas = sizeof(notas) / sizeof(int);
    for (int i = 0; i < totalNotas; i++)
    {
      const int currentNota = notas[i];float wait = duracion[i] / velocidadcancion;
      if (currentNota != 0)
      {
        tone(buzzer, notas[i], wait);
      }
      else
      {
      noTone(buzzer);
      }
      delay(wait);
    }  
}
void Play_ESPANYA()
{
const float velocidadcancion = 1.75;
int notas[] ={ 
  NOTA_G4,NOTA_D4,NOTA_B4,NOTA_G4,NOTA_D5,
  NOTA_C5,NOTA_B4,NOTA_A4,NOTA_G4,NOTA_G4,NOTA_F4,NOTA_E4,NOTA_D4, 
  NOTA_G4,NOTA_A4,NOTA_B4,0,NOTA_D5, 
  NOTA_C5,NOTA_B4,NOTA_A4,NOTA_G4,NOTA_D5,
  NOTA_G4,NOTA_D4,NOTA_B4,NOTA_G4,NOTA_D5,
  NOTA_C5,NOTA_B4,NOTA_A4,NOTA_G4,NOTA_G4,NOTA_F4,NOTA_E4,NOTA_D4, 
  NOTA_G4,NOTA_A4,NOTA_B4,0,NOTA_D5,
  
  NOTA_C5,NOTA_B4,NOTA_A4,NOTA_G4,NOTA_D5, 
  NOTA_D5,NOTA_B4,NOTA_D5,NOTA_C5,NOTA_A4,NOTA_C5, 
  NOTA_B4,NOTA_G4,NOTA_B4,NOTA_A4,NOTA_D4,NOTA_E4,NOTA_F4, 
  NOTA_G4,NOTA_A4,NOTA_B4,NOTA_C5,NOTA_D5,NOTA_C5, 
  NOTA_B4,NOTA_A4,NOTA_G4, 
  NOTA_D5,NOTA_B4,NOTA_D5,NOTA_C5,NOTA_A4,NOTA_C5, 
  NOTA_B4,NOTA_G4,NOTA_B4,NOTA_A4,NOTA_D4,NOTA_E4,NOTA_F4,
  NOTA_G4,NOTA_A4,NOTA_B4,NOTA_C5,NOTA_D5,NOTA_C5, 
  NOTA_B4,NOTA_A4,NOTA_G4 
};
int duracion[]={
  500,500,500,250,250,
  250,250,250,250,250,250,250,250,
  500,500,500,250,250,
  250,250,250,250,1000,
  500,500,500,250,250,
  250,250,250,250,250,250,250,250,
  500,500,500,250,250,
  250,250,250,250,1000,
  500,250,250,500,250,250,
  500,250,250,250,250,250,250,
  500,500,250,250,250,250,
  500,500,1000,
  500,250,250,500,250,250,
  500,250,250,250,250,250,250,
  500,500,250,250,250,250,
  500,500,1000 
};
  const int totalNotas = sizeof(notas) / sizeof(int);
  for (int i = 0; i < totalNotas; i++)
  {
    const int currentNota = notas[i];
    float wait = duracion[i] / velocidadcancion;
   
    if (currentNota != 0)
    {
      tone(buzzer, notas[i], wait);
    }
    else
    {
      noTone(buzzer);
    }
   
    delay(wait);
  }
}

void Play_Mario()
{
const float velocidadcancion = 1.25;
int notas[] ={ 
  NOTA_E5, NOTA_E5, 0, NOTA_E5,
  0, NOTA_C5, NOTA_E5, 0,
  NOTA_G5, 0, 0,  0,
  NOTA_G4, 0, 0, 0,
  NOTA_C5, 0, 0, NOTA_G4,
  0, 0, NOTA_E4, 0,
  0, NOTA_A4, 0, NOTA_B4,
  0, NOTA_AS4, NOTA_A4, 0,
  NOTE_G4, NOTE_E5, NOTA_G5,
  NOTE_A5, 0, NOTE_F5, NOTA_G5,
  0, NOTE_E5, 0, NOTA_C5,
  NOTE_D5, NOTA_B4, 0, 0,
  NOTA_C5, 0, 0, NOTA_G4,
  0, 0, NOTA_E4, 0,
  0, NOTA_A4, 0, NOTA_B4,
  0, NOTA_AS4, NOTA_A4, 0,
  NOTA_G4, NOTA_E5, NOTA_G5,
  NOTA_A5, 0, NOTA_F5, NOTA_G5,
  0, NOTA_E5, 0, NOTA_C5,
  NOTA_D5, NOTA_B4, 0, 0
  
};
int duracion[]={
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  
  175, 175, 175,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
 
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  
  175, 175, 175,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  
};
const int totalNotas = sizeof(notas) / sizeof(int);

  for (int i = 0; i < totalNotas; i++)
  {
    const int currentNota = notas[i];
    float wait = duracion[i] / velocidadcancion;
    if (currentNota != 0)
    {
      tone(buzzer, notas[i], wait);
    }
    else
    {
      noTone(buzzer);
    }
    delay(wait);
 }
}
void setup() 
{
  pinMode(29, INPUT_PULLUP); //Buton 1
  pinMode(31, INPUT_PULLUP); //Buton 2
  pinMode(33, INPUT_PULLUP); //Buton 3 
  
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
  if (digitalRead(29)==0)
      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Piratas();  }
  if (digitalRead(31)==0)
      { Serial.println("Selected -> 'Crazy Frog' ");  Play_ESPANYA();  }
  if (digitalRead(33)==0)
      { Serial.println("Selected -> 'Mario UnderWorld' ");  Play_Mario();  }
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
  on_time=millis();
  if(i>0)
  {
    button_offtime[i-1]=on_time-off_time;
  }
  while(digitalRead(BOTON_C4)==LOW);
  if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=0;
    i++;

  }
}

else if(digitalRead(BOTON_D4)==LOW)
{
tone(buzzer,frequency[1]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_D4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=1;
     i++;
 
  }
}

else if(digitalRead(BOTON_E4)==LOW)
{
tone(buzzer,frequency[2]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_E4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=2;
     i++;

  }
}

else if(digitalRead(BOTON_F4)==LOW)
{
tone(buzzer,frequency[3]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_F4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=3;
     i++;

  }
}

else if(digitalRead(BOTON_G4)==LOW)
{
tone(buzzer,frequency[4]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_G4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=4;
     i++;

  }
}

else if(digitalRead(BOTON_A4)==LOW)
{
tone(buzzer,frequency[5]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_A4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=5;
     i++;
   
  }
}

else if(digitalRead(BOTON_B4)==LOW)
{
tone(buzzer,frequency[6]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_B4)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=6;
     i++;
   
  }
}
else if(digitalRead(BOTON_C5)==LOW)
{
tone(buzzer,frequency[7]);
on_time=millis();
if(i!=0)
button_offtime[i-1]=on_time-off_time;
while(digitalRead(BOTON_C5)==LOW);
if(path==1)
  {
    off_time=millis();
    button_ontime[i]=(off_time-on_time);
    button_seq[i]=7;
     i++;
   
  }
}

noTone(buzzer);
}

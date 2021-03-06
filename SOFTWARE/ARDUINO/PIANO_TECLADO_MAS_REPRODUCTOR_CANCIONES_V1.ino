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
#include "pitches.h"
#define ACTIVATED LOW

  /*
  NOTA_C4, //DO 0
  NOTA_D4, //RE 1
  NOTA_E4, //MI 2
  NOTA_F4, //FA 3
  NOTA_G4, //SOL 4
  NOTA_A4, //LA 5
  NOTA_B4, //SI 6
  NOTA_C5, // DO 7
  */
const int BOTON_C4 = 2; //DO 1
const int BOTON_D4 = 3; //RE 2
const int BOTON_E4 = 4; //MI 3
const int BOTON_F4 = 5; //FA 4
const int BOTON_G4 = 6; //SOL 5
const int BOTON_A4 = 7; //LA 6
const int BOTON_B4 = 8; //SI 7
const int BOTON_C5 = 9; //DO 8
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
  pinMode(10, INPUT_PULLUP); //Button 1
  pinMode(11, INPUT_PULLUP); //Button 2
  pinMode(12, INPUT_PULLUP); //Button 3 
  
  Serial.begin(9600);

  pinMode(BOTON_C4, INPUT);
  digitalWrite(BOTON_C4,HIGH);
  
  pinMode(BOTON_D4, INPUT);
  digitalWrite(BOTON_D4,HIGH);
  
  pinMode(BOTON_E4, INPUT);
  digitalWrite(BOTON_E4,HIGH);
  
  pinMode(BOTON_F4, INPUT);
  digitalWrite(BOTON_F4,HIGH);

  pinMode(BOTON_G4, INPUT);
  digitalWrite(BOTON_G4,HIGH);
  
  pinMode(BOTON_A4, INPUT);
  digitalWrite(BOTON_A4,HIGH);
  
  pinMode(BOTON_B4, INPUT);
  digitalWrite(BOTON_B4,HIGH);
  
  pinMode(BOTON_C5, INPUT);
  digitalWrite(BOTON_C5,HIGH);
  
   
}
void loop()
{
  if (digitalRead(10)==0)
      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Piratas();  }
  if (digitalRead(11)==0)
      { Serial.println("Selected -> 'Himno de ESPA??A' ");  Play_ESPANYA();  }
  if (digitalRead(12)==0)
      { Serial.println("Selected -> 'Mario World' ");  Play_Mario();  }
   
   while(digitalRead(BOTON_C4) == ACTIVATED)
  {
    tone(buzzer,NOTA_C4);
  }
   while(digitalRead(BOTON_D4) == ACTIVATED)
  {
    tone(buzzer,NOTA_D4);
  }
     while(digitalRead(BOTON_E4) == ACTIVATED)
  {
    tone(buzzer,NOTA_E4);
  }
   while(digitalRead(BOTON_F4) == ACTIVATED)
  {
    tone(buzzer,NOTA_F4);
  }
     while(digitalRead(BOTON_G4) == ACTIVATED)
  {
    tone(buzzer,NOTA_G4);
  }
   while(digitalRead(BOTON_A4) == ACTIVATED)
  {
    tone(buzzer,NOTA_A4);
  }
     while(digitalRead(BOTON_B4) == ACTIVATED)
  {
    tone(buzzer,NOTA_B4);
  }
   while(digitalRead(BOTON_C5) == ACTIVATED)
  {
    tone(buzzer,NOTA_C5);
  }
  noTone(buzzer);
}

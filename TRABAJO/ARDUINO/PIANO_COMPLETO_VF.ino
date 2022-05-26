#include "pitches.h"
const int buzzer = 13;


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
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,

    NOTE_A4, NOTE_A4,
    
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,
    

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4};
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
const float velocidadcancion = 1.35;
int notas[] ={ 
  NOTE_G4,NOTE_D4,NOTE_B4,NOTE_G4,NOTE_D5,
  NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
  NOTE_G4,NOTE_A4,NOTE_B4,0,NOTE_D5, 
  NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_D5,
  NOTE_G4,NOTE_D4,NOTE_B4,NOTE_G4,NOTE_D5,
  NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
  NOTE_G4,NOTE_A4,NOTE_B4,0,NOTE_D5,
  
  NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_D5, 
  NOTE_D5,NOTE_B4,NOTE_D5,NOTE_C5,NOTE_A4,NOTE_C5, 
  NOTE_B4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_D4,NOTE_E4,NOTE_F4, 
  NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_C5, 
  NOTE_B4,NOTE_A4,NOTE_G4, 
  NOTE_D5,NOTE_B4,NOTE_D5,NOTE_C5,NOTE_A4,NOTE_C5, 
  NOTE_B4,NOTE_G4,NOTE_B4,NOTE_A4,NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_C5, 
  NOTE_B4,NOTE_A4,NOTE_G4 
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
  NOTE_E5, NOTE_E5, 0, NOTE_E5,
  0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0,  0,
  NOTE_G4, 0, 0, 0,
  NOTE_C5, 0, 0, NOTE_G4,
  0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4,
  0, NOTE_AS4, NOTE_A4, 0,
  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, 0, NOTE_F5, NOTE_G5,
  0, NOTE_E5, 0, NOTE_C5,
  NOTE_D5, NOTE_B4, 0, 0,
  NOTE_C5, 0, 0, NOTE_G4,
  0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4,
  0, NOTE_AS4, NOTE_A4, 0,
  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, 0, NOTE_F5, NOTE_G5,
  0, NOTE_E5, 0, NOTE_C5,
  NOTE_D5, NOTE_B4, 0, 0
  
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
      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Piratas();  
        }
     if (digitalRead(31)==0)
      { Serial.println("Selected -> 'Himno de España' ");  Play_ESPANYA();  
        }
     if (digitalRead(33)==0)
      { Serial.println("<\nSelected -> 'Mario UnderWorld' ");  Play_Mario();  
        }
      
if(path==0)
{
  //Serial.println("playback");
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
  Serial.println("DO");
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
  Serial.println("RE");
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
  Serial.println("MI");
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
  Serial.println("FA");
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
  Serial.println("SOL");
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
  Serial.println("LA");
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
  Serial.println("SI");
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
  Serial.println("DO'");
}

noTone(buzzer);  

    
}

#include "pitches.h"
#define buzzer 8

#define pin1 A0
#define pin2 A1
#define pin3 A2
#define pin4 A3
#define pin5 A4
#define pin6 A5
#define pin7 A6
#define pin8 A7

int nota[] = {
  NOTE_C3, //DO 0
  NOTE_D3, //RE 1
  NOTE_E3, //MI 2
  NOTE_F3, //FA 3
  NOTE_G3, //SOL 4
  NOTE_A3, //LA 5
  NOTE_B3, //SI 6
  NOTE_C2, //DO 7 
};

short tiempo = 8;

enum Estados {MODO_MANUAL};
Estados estado=MODO_MANUAL;

String mensaje_entrada;
String mensaje_salida;

void setup() {
  Serial.begin(9600);
 
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, INPUT);
  pinMode(pin8, INPUT);
  pinMode(buzzer, OUTPUT);
}
 void loop()
  {
     while(digitalRead(pin1) == LOW)
    {
      tone(buzzer, nota[0], 100);
  
    }
    while(digitalRead(pin2) == LOW)
    {
      tone(buzzer, nota[1], 100);
    }
  
    while(digitalRead(pin3) == LOW)
    {
      tone(buzzer, nota[2], 100);
    }
    
    while(digitalRead(pin4) == LOW)
    {
      tone(buzzer, nota[3], 100);
    }
  
    while(digitalRead(pin5) == LOW)
    {
      tone(buzzer, nota[4], 100);
    }
  
    while(digitalRead(pin6) == LOW)
    {
      tone(buzzer, nota[5], 100);
    }
  
    while(digitalRead(pin7) == LOW)
    {
      tone(buzzer, nota[6], 100);
    }      
  
    while(digitalRead(pin8) == LOW)
    {
      tone(buzzer, nota[7], 100);
    }  
 
    noTone(buzzer);
 
    procesar_mensajes();
  }
void procesar_mensajes(void)
{
  if( Serial.available()> 0) 
  {
    mensaje_entrada = Serial.readStringUntil('\n');
    if (mensaje_entrada.compareTo("GET_NOTAS")==0)
    {
      int notas = ping(TriggerPin, EchoPin);
      mensaje_salida=String("NOTAS="+String(cm,3));
    }
      else
        mensaje_salida="COMANDO DESCONOCIDO";

    Serial.println(mensaje_salida);
  }
}

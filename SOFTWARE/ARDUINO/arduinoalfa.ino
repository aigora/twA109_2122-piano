#include "pitches.h"
#define buzzer 8

#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7
#define pin7 8
#define pin8 9

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
    while(digitalRead(pin1) == HIGH)
    {
      tone(buzzer, NOTA_C3, 100);
  
    }
    while(digitalRead(pin2) == HIGH)
    {
      tone(buzzer, NOTA_D3, 100);
    }
  
    while(digitalRead(pin3) == HIGH)
    {
      tone(buzzer, NOTA_E3, 100);
    }
    
    while(digitalRead(pin4) == HIGH)
    {
      tone(buzzer, NOTA_F3, 100);
    }
  
    while(digitalRead(pin5) == HIGH)
    {
      tone(buzzer, NOTA_G3, 100);
    }
  
    while(digitalRead(pin6) == HIGH)
    {
      tone(buzzer, NOTA_A3, 100);
    }
  
    while(digitalRead(pin7) == HIGH)
    {
      tone(buzzer, NOTA_B3, 100);
    }      
  
    while(digitalRead(pin8) == HIGH)
    {
      tone(buzzer, NOTA_C2, 100);
    }  
 
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

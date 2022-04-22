//Codigo inicial sin conectar mediante serial al codigo C++

#include <pitches.h>
#define zumba 7
/*Botones-Teclas*/

#define b1 A0
#define b2 A1
#define b3 A2
#define b4 A3
#define b5 A4
#define b6 A5
#define b7 2

short t = 7;

/*Notas Musicales*/
int nota[] = {
  NOTE_DO, //
  NOTE_RE, //
  NOTE_MI, //
  NOTE_FA, //
  NOTE_SOL, //
  NOTE_LA, //
  NOTE_SI, //
};
void setup() {

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);
  pinMode(b6, INPUT);
  pinMode(b7, INPUT);
  pinMode(zumba, OUTPUT);
}
void loop() {

  if (digitalRead(b1)) {
    tone(zumba, nota[0], t);
  }
  if (digitalRead(b2)) {
    tone(zumba, nota[1], t);
  }
  if (digitalRead(b3)) {
    tone(zumba, nota[2], t);
  }
  if (digitalRead(b4)) {
    tone(zumba, nota[3], t);
  }
  if (digitalRead(b5)) {
    tone(zumba, nota[4], t);
  }
  if (digitalRead(b6)) {
    tone(zumba, nota[5], t);
  }
  if (digitalRead(b7) {
    tone(zumba, nota[6], t);
  }
}

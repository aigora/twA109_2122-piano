//PRUEBA CANCIÓN DE  PIRATAS DEL CARIBE

//PRUEBA CANCIÓN DE  PIRATAS DEL CARIBE

const int buzzer = 12;
const float velocidadcancion = 0.8;

#define NOTA_C4 262
#define NOTA_D4 294
#define NOTA_E4 330
#define NOTA_F4 349
#define NOTA_G4 392
#define NOTA_A4 440
#define NOTA_B4 494
#define NOTA_C5 523
#define NOTA_D5 587
#define NOTA_E5 659
#define NOTA_F5 698
#define NOTA_G5 784
#define NOTA_A5 880
#define NOTA_B5 988

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

void setup()
{
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

void loop()
{

}

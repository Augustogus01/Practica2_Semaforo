#include "Arduino.h"
#include "teclas.h"
#include <retardo.h>

typedef enum{
  NORMAL,
  DESCONECTADO,
  ALARMA
}fnsemaforo_t;

fnsemaforo_t fnsemaforo;

void fnormal(void)
{
    switch (fnsemaforo)
  {
  case NORMAL:
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, LOW);
    delay(2000);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    delay(3000);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    delay(500);
    break;
  case DESCONECTADO:
        digitalWrite(LED_AMARILLO, HIGH);
        delay(500);
  break;

  case ALARMA:
            digitalWrite(LED_ROJO, HIGH);
            delay(1000);
  break;
  default:
        fsmButtonError();
    break;
  }
}

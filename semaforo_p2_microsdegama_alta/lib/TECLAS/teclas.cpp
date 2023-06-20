#include <teclas.h>
#include <Arduino.h>
#include <semaforo.h>
#include <retardo.h>

typedef enum{
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_FALLING,
  BUTTON_RISING
}fsmButtonState_t;

typedef enum{
  BUTTON_UP1,
  BUTTON_DOWN1,
  BUTTON_FALLING1,
  BUTTON_RISING1
}fsmButtonState_t1;

fsmButtonState_t fsmButtonState;                                //Variable de estado global
fsmButtonState_t1 fsmButtonState1;

/************************Maquina de estados boton 1****************************/
void fsmButtonInit(void){
  fsmButtonState=BUTTON_UP;
}

void fsmButtonUpdate(int16_t SW){
  switch (fsmButtonState)
  {
  case BUTTON_UP:
    if(!digitalRead(SW)){
        fsmButtonState=BUTTON_FALLING;
    }
    break;
  case BUTTON_DOWN:
  if (digitalRead(SW)){
    fsmButtonState=BUTTON_RISING;
  }
    break;
  case BUTTON_FALLING:    
    if (nbDelay(40)){
        if(!digitalRead(SW)){
            fsmButtonState=BUTTON_DOWN;
            /*fsmButtonState=DESCONECTADO;*/
            buttonPressed();                              //Detección de flanco
        }else{
          fsmButtonState=BUTTON_UP;
        }
    }    
    break;
  case BUTTON_RISING:   
    if(nbDelay(40)){
      if(!digitalRead(SW)){
        fsmButtonState=BUTTON_UP;
        buttonReleased();
      }else{
        fsmButtonState= BUTTON_DOWN;
      }
    }     
    break;

  default:
    fsmButtonError();
    break;

  }
}

void fsmButtonError(void){
  fsmButtonState=BUTTON_UP;
}

void buttonPressed(void){
  fnsemaforo=DESCONECTADO;
}
void buttonReleased(void){
  fnsemaforo=ALARMA;

}
/************************************************************************/
/**********************Maquina de estados boton 2****************************************/
void fsmButtonInit1(void){
  fsmButtonState1=BUTTON_UP1;
}

void fsmButtonUpdate1(int16_t SWA){
  switch (fsmButtonState1)
  {
  case BUTTON_UP1:
    if(!digitalRead(SWA)){
        fsmButtonState1=BUTTON_FALLING1;
    }
    break;
  case BUTTON_DOWN1:
  if (digitalRead(SWA)){
    fsmButtonState1=BUTTON_RISING1;
  }
    break;
  case BUTTON_FALLING1:    
    if (nbDelay(40)){
        if(!digitalRead(SWA)){
            fsmButtonState1=BUTTON_DOWN1;
            buttonPressed1();                              //Detección de flanco
        }else{
          fsmButtonState1=BUTTON_UP1;
        }
    }    
    break;
  case BUTTON_RISING1:   
    if(nbDelay(40)){
      if(!digitalRead(SWA)){
        fsmButtonState1=BUTTON_UP1;
        buttonReleased1();
      }else{
        fsmButtonState1= BUTTON_DOWN1;
      }
    }     
    break;

  default:
    fsmButtonError1();
    break;

  }
}

void fsmButtonError1(void){
  fsmButtonState1=BUTTON_UP1;
}

void buttonPressed1(void){
    fnsemaforo=NORMAL;
}
void buttonReleased1(void){
    fnsemaforo=NORMAL;
}

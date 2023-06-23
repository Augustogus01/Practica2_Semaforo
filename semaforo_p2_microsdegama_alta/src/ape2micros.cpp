#include <Arduino.h>
#include <teclas.h>
#include <semaforo.h>
#include <retardo.h>

const int16_t LED_VERDE=2;
const int16_t LED_AMARILLO=3;
const int16_t LED_ROJO=4;
const int16_t LED_AZUL=5;
const int16_t SW1=10;
const int16_t SW2=11;

/******************************Functions prototypes*******************************/
/******************************FuncIONES BOTON 1*******************************/
/*****************************************************************************/
/*int16_t t_tAcc;*/

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  //prev_time=millis();
 
}
/*********************************************************************/
/****************************PROGRAMA PRINCIPAL*************************************/
void loop() {
  fsmButtonInit();
  fsmButtonInit1();
  while(1){
    fsmButtonUpdate(SW1);
    fsmButtonUpdate1(SW2);
    fnormal();
  }
}


/************************Maquina de estados boton 1****************************/


/*******************SEMAFORO FUNCIONANDO NORMAL*****************************/


/********************Retrasos no bloqueantes*********************/

#ifndef __TECLAS_H__
#define __TECLAS_H__
#include <Arduino.h>
#include <semaforo.h>
/******************************FuncIONES BOTON 1*******************************/
void fsmButtonInit(void);
void fsmButtonUpdate(int16_t SW);
void fsmButtonError(void);
void buttonPressed(void);
void buttonReleased(void);
/*********************************************************************/

/****************FUNCIONES BOTON 2***********************************/
void fsmButtonUpdate1(int16_t SWA);
void fsmButtonInit1(void);
void fsmButtonError1(void);
void buttonPressed1(void);
void buttonReleased1(void);

#endif // __TECLAS_H__
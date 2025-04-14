// Systick.h
// Runs on TM4C123
// CECS 347 Project 2 - Space Invaders
// Group number:
// Group members:



// SysTick.h
// Runs on TM4C123
// By Dr. Min He
// December 10th, 2018
 
#include <stdint.h>

// Time delay using busy wait.
void SysTick_Wait1us(uint8_t delay);
void SysTick_Init(void);
void SysTick_Stop(void);
uint32_t SysTick_Get_MC_Elapsed(void);
void SysTick_Wait(uint32_t delay);
void SysTick_Wait_0_1sec(void);

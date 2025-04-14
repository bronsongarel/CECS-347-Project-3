// Systick.h
// Runs on TM4C123
// CECS 347 Project 3 - Space Invaders
// Group number: 9
// Group members: Jose Ambriz, Bronson Garel, Jonathan Kim, Kyle Wyckoff

#include <stdint.h>

// Time delay using busy wait.
void SysTick_Wait1us(uint8_t delay);
void SysTick_Init(void);
void SysTick_Stop(void);
uint32_t SysTick_Get_MC_Elapsed(void);
void SysTick_Wait_0_1sec(void);
void SysTick_BusyWait_0_1sec(uint8_t delay);

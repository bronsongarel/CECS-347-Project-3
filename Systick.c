// Systick.c
// Runs on TM4C123
// CECS 347 Project 3 - Space Invaders
// Group number: 9
// Group members: Jose Ambriz, Bronson Garel, Jonathan Kim, Kyle Wyckoff

#include <stdint.h>
#include "SysTick.h"
#include "tm4c123gh6pm.h"

#define ONE_MICRO_SECOND          16     	// number of machine cycles to generate 1us delay for 16MHz system clock
#define POINT_ONE_SECOND					8000000 // number of machine cycles to generate 0.1 delay for 50MHz system clock
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M; // number of counts to wait
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000;
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_INTEN;
}

// Disable Systick timer
void SysTick_Stop(void){
	NVIC_ST_CTRL_R = 0;
}

// Calculate number of machine cycles elapsed
uint32_t SysTick_Get_MC_Elapsed(void){
	return NVIC_ST_RELOAD_R-NVIC_ST_CURRENT_R;
}

void SysTick_Wait_0_1sec(void){
	NVIC_ST_RELOAD_R = POINT_ONE_SECOND-1; // number of counts to wait
	NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
	//while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT)==0); // wait for count flag
	//NVIC_ST_CTRL_R = 0;
}

void SysTick_BusyWait_0_1sec(uint8_t delay){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_INTEN;
	while(delay > 0){
		NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
		NVIC_ST_RELOAD_R = POINT_ONE_SECOND-1; // number of counts to wait
		NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
		NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
		while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT)==0); // wait for count flag
		NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
		delay--;
	}
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;
}

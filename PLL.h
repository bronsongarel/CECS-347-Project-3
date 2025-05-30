// PLL.h
// Runs on TM4C123
// CECS 347 Project 3 - Space Invaders
// Group number: 9
// Group members: Jose Ambriz, Bronson Garel, Jonathan Kim, Kyle Wyckoff

// TODO:
// Determine the #define statement SYSDIV initializes
// the PLL to the desired frequency.
#define SYSDIV 4
// bus frequency is 400MHz/(SYSDIV+1) = 400MHz/(5) = 50MHz
#define SYSCTL_RIS_R 						(*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RIS_PLLLRIS 			0x00000040 // PLL Lock Raw Interrupt Status
#define SYSCTL_RCC_R 						(*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC_XTAL_M 			0x000007C0 // Crystal Value
#define SYSCTL_RCC_XTAL_6MHZ 		0x000002C0 // 6 MHz Crystal
#define SYSCTL_RCC_XTAL_8MHZ 		0x00000380 // 8 MHz Crystal
#define SYSCTL_RCC_XTAL_16MHZ 	0x00000540 // 16 MHz Crystal
#define SYSCTL_RCC2_R 					(*((volatile unsigned long *)0x400FE070))
#define SYSCTL_RCC2_USERCC2 		0x80000000 // Use RCC2
#define SYSCTL_RCC2_DIV400 			0x40000000 // Divide PLL as 400 MHz vs. 200 MHz
#define SYSCTL_RCC2_SYSDIV2_M 	0x1F800000 // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2LSB 	0x00400000 // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_PWRDN2 			0x00002000 // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2 		0x00000800 // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M 	0x00000070 // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO 	0x00000000 // MOSC
void PLL_Init(void);

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ISR.H
 *       Module:  Interrupt Service Routine
 *
 *  Description:  Header file of Interrupt Service Routine for (General-Purpose Timer Driver)   
 *  
 *********************************************************************************************************************/
#ifndef ISR.H
#define ISR.H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
extern uint8 TICKS ;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer0A_ISR(void);
void TIMER0B_ISR(void);
void TIMER1A_ISR(void);
void Timer1B_ISR(void);
void Timer2A_ISR(void);
void Timer2B_ISR(void);
void Timer3A_ISR(void);
void Timer3B_ISR(void);
void Timer4A_ISR(void);
void Timer4B_ISR(void);
void Timer5A_ISR(void);
void Timer5B_ISR(void);
void Timer0A_WIDE_ISR(void);
void Timer0B_WIDE_ISR(void);
void Timer1A_WIDE_ISR(void);
void Timer1B_WIDE_ISR(void);
void Timer2A_WIDE_ISR(void);
void Timer2B_WIDE_ISR(void);
void Timer3A_WIDE_ISR(void);
void Timer3B_WIDE_ISR(void);
void Timer4A_WIDE_ISR(void);
void Timer4B_WIDE_ISR(void);
void Timer5A_WIDE_ISR(void);
void Timer5B_WIDE_ISR(void);
 
#endif  /* ISR.H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

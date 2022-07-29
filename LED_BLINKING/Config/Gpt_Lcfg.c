/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt_Lcfg.c
 *        \brief  Gpt_Lcfg
 *
 *      \details  General-Purpose Timer Link Configuration Source File
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gptm.h"
#include "App.h"
#include "Isr.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern void Timer0A_ISR(void);
extern void TIMER0B_ISR(void);
extern void TIMER1A_ISR(void);
extern void Timer1B_ISR(void);
extern void Timer2A_ISR(void);
extern void Timer2B_ISR(void);
extern void Timer3A_ISR(void);
extern void Timer3B_ISR(void);
extern void Timer4A_ISR(void);
extern void Timer4B_ISR(void);
extern void Timer5A_ISR(void);
extern void Timer5B_ISR(void);
extern void Timer0A_WIDE_ISR(void);
extern void Timer0B_WIDE_ISR(void);
extern void Timer1A_WIDE_ISR(void);
extern void Timer1B_WIDE_ISR(void);
extern void Timer2A_WIDE_ISR(void);
extern void Timer2B_WIDE_ISR(void);
extern void Timer3A_WIDE_ISR(void);
extern void Timer3B_WIDE_ISR(void);
extern void Timer4A_WIDE_ISR(void);
extern void Timer4B_WIDE_ISR(void);
extern void Timer5A_WIDE_ISR(void);
extern void Timer5B_WIDE_ISR(void);

const Gpt_ConfigType Gpt_ConfigPtr = {
			 TIMER0_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_ON ,GPT_CONTINUOUS,Timer0A_ISR     ,
		   TIMER0_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,TIMER0B_ISR     ,
			 TIMER1_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,TIMER1A_ISR     ,
			 TIMER1_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer1B_ISR     ,
			 TIMER2_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer2A_ISR     ,
			 TIMER2_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer2B_ISR     ,
			 TIMER3_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer3A_ISR     ,
			 TIMER3_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer3B_ISR     ,
			 TIMER4_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer4A_ISR     ,
			 TIMER4_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer4B_ISR     ,
			 TIMER5_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer5A_ISR     ,
			 TIMER5_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer5B_ISR     ,
			 TIMER0_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer0A_WIDE_ISR,
			 TIMER0_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer0B_WIDE_ISR,
			 TIMER1_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer1A_WIDE_ISR,
			 TIMER1_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer1B_WIDE_ISR,
			 TIMER2_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer2A_WIDE_ISR,
			 TIMER2_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer2B_WIDE_ISR,
			 TIMER3_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer3A_WIDE_ISR,
			 TIMER3_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer3B_WIDE_ISR,
			 TIMER4_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer4A_WIDE_ISR,
			 TIMER4_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer4B_WIDE_ISR,
			 TIMER5_A_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer5A_WIDE_ISR,
			 TIMER5_B_WIDE  ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_OFF,GPT_CONTINUOUS,Timer5B_WIDE_ISR
};
	
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/

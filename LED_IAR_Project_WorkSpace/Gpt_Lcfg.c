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
extern void Timer1A_ISR(void);

const Gpt_ConfigType Gpt_ConfigPtr = {
			 TIMER0_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_ON ,GPT_CONTINUOUS,Timer0A_ISR,
                         TIMER0_B       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_ON ,GPT_CONTINUOUS,NULL_PTR,
			 TIMER1_A       ,GPT_MODE_NORMAL,INITIALIZED,TickFrequency,TickValueMax,INTERRUPT_ON ,GPT_CONTINUOUS,Timer1A_ISR,
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

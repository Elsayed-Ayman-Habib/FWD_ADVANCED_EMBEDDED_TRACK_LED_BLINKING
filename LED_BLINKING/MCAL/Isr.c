/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ISR.C
 *        \brief  Interrupt Service Routine
 *
 *      \details  Source file of Interrupt Service Routine for (General-Purpose Timer Driver)  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
volatile static uint8 TICKS = 0;
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
* \Syntax          : void Timer0A_ISR()        
* \Description     : Interrupt Service Routine of Timer0_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer0A_ISR()
 {
     TICKS++;
 }

 /******************************************************************************
* \Syntax          : void Timer0B_ISR()        
* \Description     : Interrupt Service Routine of Timer0_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void TIMER0B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer1A_ISR()        
* \Description     : Interrupt Service Routine of Timer1_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void TIMER1A_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer1B_ISR()        
* \Description     : Interrupt Service Routine of Timer1_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer1B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer2A_ISR()        
* \Description     : Interrupt Service Routine of Timer2_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer2A_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer2B_ISR()        
* \Description     : Interrupt Service Routine of Timer2_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer2B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer3A_ISR()        
* \Description     : Interrupt Service Routine of Timer3_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer3A_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer3B_ISR()        
* \Description     : Interrupt Service Routine of Timer3_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer3B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer4A_ISR()        
* \Description     : Interrupt Service Routine of Timer4_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer4A_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer4B_ISR()        
* \Description     : Interrupt Service Routine of Timer4_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer4B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer5A_ISR()        
* \Description     : Interrupt Service Routine of Timer5_A                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer5A_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer5B_ISR()        
* \Description     : Interrupt Service Routine of Timer5_B                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer5B_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer0A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer0_A_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer0A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer0B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer0_B_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer0B_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer1A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer1_A_Wide                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer1A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer1B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer1_B_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer1B_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer2A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer2_A_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer2A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer2B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer2_B_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer2B_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer3A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer3_A_Wide                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer3A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer3B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer3_B_Wide                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer3B_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer4A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer4_A_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer4A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer4B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer4_B_Wide                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer4B_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer5A_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer5_A_Wide                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer5A_WIDE_ISR(){}

 /******************************************************************************
* \Syntax          : void Timer5B_WIDE_ISR()       
* \Description     : Interrupt Service Routine of Timer5_B_Wide                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Timer5B_WIDE_ISR(){}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/

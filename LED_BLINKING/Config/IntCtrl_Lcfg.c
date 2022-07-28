/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  IntCtrl_Lcfg
 *
 *      \details  IntCtrl Link Configuration Source File
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const IntCtrl_ConfigType IntCtrl_ConfigPtr = {                                      
  INTCTRL_RESET                                            ,RESET_GROUP_PRIORITY                 ,RESET_SUP_GROUP_PRIORITY                 ,
  INTCTRL_NON_MASKABLE_INTERRUPT                           ,NON_MASKABLE_INTERRUPT_GROUP_PRIORITY,NON_MASKABLE_INTERRUPT_SUP_GROUP_PRIORITY,
  INTCTRL_HARD_FAULT                                       ,HARD_FAULT_GROUP_PRIORITY            ,HARD_FAULT_SUP_GROUP_PRIORITY            ,
  INTCTRL_MEMORY_MANAGEMENT_FAULT                          ,INTCTRL_GROUP7                       ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_BUS_FAULT                                        ,INTCTRL_GROUP7                       ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_USAGE_FAULT                                      ,INTCTRL_GROUP7                       ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SVCALL                                           ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_DEBUG_MONITOR                                    ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PENDSV                                           ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SYSTICK                                          ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTA_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTB_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTC_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTD_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTE_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART0_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART1_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SSI0_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_I2C0_INTERRUPT 								  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM0_FAULT_INTERRUPT							  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM0_GENERATOR_0_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM0_GENERATOR_1_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM0_GENERATOR_2_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_QEI0_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC0_SEQUENCE_0_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC0_SEQUENCE_1_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC0_SEQUENCE_2_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC0_SEQUENCE_3_INTERRUPT 						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_WATCHDOG_TIMER_0_AND_1_INTERRUPT			      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_0_A_INTERRUPT  			      ,INTCTRL_GROUP0				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_0_B_INTERRUPT				      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_1_A_INTERRUPT					  ,INTCTRL_GROUP1				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_1_B_INTERRUPT                    ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_2_A_INTERRUPT					  ,INTCTRL_GROUP2				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_2_B_INTERRUPT                    ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ANALOG_COMPARATOR_0_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ANALOG_COMPARATOR_1_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SYSTEM_CONTORL_INTERRUPT                         ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL_INTERRUPT,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_GPIO_PORTF_INTERRUPT							  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART2_INTERRUPT							      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SSI1_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_3_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_3_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_I2C1_INTERRUPT									  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                      
  INTCTRL_QEI1_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_CAN0_INTERRUPT									  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_CAN1_INTERRUPT								      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_HIBERNATION_MODULE_INTERRUPT				      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_USB_INTERRUPT								      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM_GENERATOR_3_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UDMA_SOFTWARE_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UDMA_ERROR_INTERRUPT							  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC1_SEQUENCE_0_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC1_SEQUENCE_1_INTERRUPT					      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC1_SEQUENCE_2_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_ADC1_SEQUENCE_3_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SSI2_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SSI3_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART3_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART4_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART5_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART6_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_UART7_INTERRUPT                                  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_I2C2_INTERRUPT                                   ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_I2C3_INTERRUPT 								  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_4_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_4_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_5_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_16_32_BIT_TIMER_5_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_0_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_0_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_1_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_1_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_2_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_2_B_INTERRUPT				   	  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_3_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_3_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_4_A_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_4_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_5_A_INTERRUPT				      ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_32_64_BIT_TIMER_5_B_INTERRUPT					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_SYSTEM_EXEPTION_INTERRUPT   					  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_PWM1_GENERATOR_1_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM1_GENERATOR_1_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM1_GENERATOR_2_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,
  INTCTRL_PWM1_GENERATOR_3_INTERRUPT						  ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                        ,                       
  INTCTRL_PWM1_FAULT_INTERRUPT                             ,INTCTRL_GROUP7				        ,INTCTRL_SUBGROUP7                   
    
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

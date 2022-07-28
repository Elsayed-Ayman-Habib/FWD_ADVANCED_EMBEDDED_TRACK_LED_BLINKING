/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  Nested Vector Interrupt Driver
 *
 *  Description:  The Configure Of All MCU interrupts Priority into gorups and subgroups
 *                and Enable NVIC Interrupt Gate for Peripherals     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL.H
#define INTCTRL.H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Common_Macros.h"
#include "IntCtrl_Cfg.h"
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 IntCtrl_InterruptType ;

typedef uint32 InterruptPeripheralGates ;

typedef uint8 InterruptGroupPriority ;

typedef uint8 InterruptSub_GroupPriority ;


typedef struct{
	IntCtrl_InterruptType IntCtrl_Exeption_And_Interrupt_Number;
	InterruptGroupPriority group;
	InterruptSub_GroupPriority sub_group;
}IntCtrl_ConfigChannel;

typedef struct
{
	IntCtrl_ConfigChannel Interrupt[INTCTRL_CONFIGURED_INTERRUPT];
}IntCtrl_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const IntCtrl_ConfigType IntCtrl_ConfigPtr;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_init(void);
 
#endif  /* INTCTRL.H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
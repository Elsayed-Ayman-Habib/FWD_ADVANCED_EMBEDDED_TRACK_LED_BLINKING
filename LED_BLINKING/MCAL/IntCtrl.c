/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Nested Vector Interrupt Driver
 *
 *      \details  Source file for Nested Vector Interrupt Driver 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "IntCtrl_Regs.h"
#include "IntCtrl_Cfg.h"
#include "tm4c123gh6pm_registers.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
STATIC const IntCtrl_ConfigChannel * IntCtrl_Configuration = NULL_PTR;
STATIC uint8 IntCtrl_Status = INTCTRL_NOT_INITIALIZED ;
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
* \Syntax          : void IntCtrl_init(void)        
* \Description     : Function to Init the Nested Vector Interrupt driver                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
 void IntCtrl_init(const IntCtrl_ConfigType* ConfigPtr)
{
	 IntCtrl_Status        = INTCTRL_INITIALIZED;
         IntCtrl_Configuration = ConfigPtr->Interrupt;
	 volatile uint32 * IntCtrl_Interrupt_Ptr = (volatile uint32 *)INTCTRL_BASE_ADDRESS;
	 
	 for(uint8 i = 0; i < INTCTRL_CONFIGURED_INTERRUPT ; i++)
	 {
		 
		/* 
		 *enable the corresponding interrupt 
		 */
		 
		if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (16)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (47)))
		{
		  SET_BIT(*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_EN0_BASE_OFFSET) , (((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)+(16))%(32)));
		}
		else  if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (48)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (79)))
		{
		  SET_BIT(*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_EN1_BASE_OFFSET) , (((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)+(16))%(32)));
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (80)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (111)))
		{
		  SET_BIT(*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_EN2_BASE_OFFSET) , (((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)+(16))%(32)));
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (112)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (143)))
		{
		  SET_BIT(*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_EN3_BASE_OFFSET) , (((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)+(16))%(32)));
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (144)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (154)))
		{
		  SET_BIT(*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_EN4_BASE_OFFSET) , (((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)+(16))%(32)));
		}
		else 
		{
			 /* Do Nothing */
		}
		
		/*
		 *The APINT register provides priority grouping control for the exception model , This field determines the split of group priority from subpriority 
		 */	
		 
		if ( (IntCtrl_Configuration[i].group == INTCTRL_GROUP7) && (IntCtrl_Configuration[i].sub_group == INTCTRL_SUBGROUP0) )
		{
			*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_APINT_BASE_OFFSET) = ((((INTCTRL_VALUE_TO_WRITE_NUMBER) << (APINT_VECTKEY_NUM))&((INTCTRL_APINT_VECTKEY_MASK)))+((NVIC_PRIORITY_GROUPS_7_SUB_0) << (APINT_PRIGROUP_NUM))); 
		}
		else if ( (IntCtrl_Configuration[i].group == INTCTRL_GROUP0) && (IntCtrl_Configuration[i].sub_group == INTCTRL_SUBGROUP7) )
		{
			*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_APINT_BASE_OFFSET) = ((((INTCTRL_VALUE_TO_WRITE_NUMBER) << (APINT_VECTKEY_NUM))&((INTCTRL_APINT_VECTKEY_MASK)))+((NVIC_PRIORITY_GROUPS_0_SUB_7) << (APINT_PRIGROUP_NUM)));
		}
		else if ( (IntCtrl_Configuration[i].group == INTCTRL_GROUP3) && (IntCtrl_Configuration[i].sub_group == INTCTRL_SUBGROUP1) )
		{
			*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_APINT_BASE_OFFSET) = ((((INTCTRL_VALUE_TO_WRITE_NUMBER) << (APINT_VECTKEY_NUM))&((INTCTRL_APINT_VECTKEY_MASK)))+((NVIC_PRIORITY_GROUPS_3_SUB_1) << (APINT_PRIGROUP_NUM)));
		}
		else if ( (IntCtrl_Configuration[i].group == INTCTRL_GROUP1) && (IntCtrl_Configuration[i].sub_group == INTCTRL_SUBGROUP3) )
		{
			*(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_APINT_BASE_OFFSET) = ((((INTCTRL_VALUE_TO_WRITE_NUMBER) << (APINT_VECTKEY_NUM))&((INTCTRL_APINT_VECTKEY_MASK)))+((NVIC_PRIORITY_GROUPS_1_SUB_3) << (APINT_PRIGROUP_NUM)));
		}
		else 
		{
			 /* Do Nothing */
		}
		
		/* 
		 *set the priority 
		 */
		 
		if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (16)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (19)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI0_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI0_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI0_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI0_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI0_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI0_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI0_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI0_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (20)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (23)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI1_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI1_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI1_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI1_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI1_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI1_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI1_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI1_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (24)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (27)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI2_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI2_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI2_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI2_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI2_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI2_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI2_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI2_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (28)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (31)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI3_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI3_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI3_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI3_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI3_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI3_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI3_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI3_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (32)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (35)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI4_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI4_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI4_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI4_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI4_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI4_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI4_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI4_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (36)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (39)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI5_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI5_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI5_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI5_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI5_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI5_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI5_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI5_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (40)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (43)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI6_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI6_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI6_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI6_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI6_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI6_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI6_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI6_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (44)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (47)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI7_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI7_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI7_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI7_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI7_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI7_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI7_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI7_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (48)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (51)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI8_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI8_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI8_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI8_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI8_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI8_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI8_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI8_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (52)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (55)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI9_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI9_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI9_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI9_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI9_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI9_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI9_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI9_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (56)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (59)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI10_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI10_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI10_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI10_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI10_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI10_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI10_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI10_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (60)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (63)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI11_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI11_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI11_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI11_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI11_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI11_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI11_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI11_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (64)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (67)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI12_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI12_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI12_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI12_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI12_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI12_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI12_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI12_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (68)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (71)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI13_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI13_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI13_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI13_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI13_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI13_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI13_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI13_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (72)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (75)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI14_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI14_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI14_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI14_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI14_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI14_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI14_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI14_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (76)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (79)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI15_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI15_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI15_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI15_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI15_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI15_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI15_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI15_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (80)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (83)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI16_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI16_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI16_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI16_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI16_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI16_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI16_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI16_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (84)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (87)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI17_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI17_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI17_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI17_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI17_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI17_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI17_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI17_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (88)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (91)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI18_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI18_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI18_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI18_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI18_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI18_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI18_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI18_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (92)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (95)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI19_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI19_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI19_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI19_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI19_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI19_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI19_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI19_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (96)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (99)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI20_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI20_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI20_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI20_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI20_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI20_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI20_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI20_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (100)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (103)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI21_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI21_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI21_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI21_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI21_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI21_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI21_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI21_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (104)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (107)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI22_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI22_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI22_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI22_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI22_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI22_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI22_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI22_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (108)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (111)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI23_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI23_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI23_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI23_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI23_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI23_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI23_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI23_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (112)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (115)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI24_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI24_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI24_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI24_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI24_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI24_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI24_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI24_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (116)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (119)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI25_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI25_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI25_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI25_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI25_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI25_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI25_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI25_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (120)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (123)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI26_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI26_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI26_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI26_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI26_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI26_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI26_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI26_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (124)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (127)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI27_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI27_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI27_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI27_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI27_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI27_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI27_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI27_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (128)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (131)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI28_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI28_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI28_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI28_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI28_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI28_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI28_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI28_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (132)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (135)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI29_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI29_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI29_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI29_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI29_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI29_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI29_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI29_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (136)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (139)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI30_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI30_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI30_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI30_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI30_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI30_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI30_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI30_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (140)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (143)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI31_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI31_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI31_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI31_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI31_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI31_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI31_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI31_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (144)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (147)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI32_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI32_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI32_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI32_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI32_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI32_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI32_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI32_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (148)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (151)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI33_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI33_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI33_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI33_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI33_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI33_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
			  case 3 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI33_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI33_BASE_OFFSET )&(INTCTRL_PRIX_INTD_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTD_NUM)));
			  break;
		  }
		}
		else if ((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number >= (152)) && (IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number <= (154)))
		{
		 switch(((IntCtrl_Configuration[i].IntCtrl_Exeption_And_Interrupt_Number)-(16))%(4))
		  {
			  case 0 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI34_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI34_BASE_OFFSET )&(INTCTRL_PRIX_INTA_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTA_NUM)));
			  break;
			  case 1 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI34_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI34_BASE_OFFSET )&(INTCTRL_PRIX_INTB_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTB_NUM)));
			  break;
			  case 2 : *(volatile uint32 *)((volatile uint8 *)IntCtrl_Interrupt_Ptr + INTCTRL_PRI34_BASE_OFFSET) = ((( INTCTRL_PRIX_BASE_ADDRESS + INTCTRL_PRI34_BASE_OFFSET )&(INTCTRL_PRIX_INTC_MASK))|((IntCtrl_Configuration[i].group) << (PRIX_INTC_NUM)));
			  break;
		  }
		}
		else 
		{
		/* Do Nothing */
		}
	 }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/

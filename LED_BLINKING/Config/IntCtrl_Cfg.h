/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  Nested Vector Interrupt Configration
 *
 *  Description:  Port Configuration Header file     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG.H
#define INTCTRL_CFG.H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTCTRL_CONFIGURED_INTERRUPT  (154U)

/* Vector Number Of Exeptions Types */

#define INTCTRL_RESET                    (1U)
#define INTCTRL_NON_MASKABLE_INTERRUPT   (2U)
#define INTCTRL_HARD_FAULT               (3U)
#define INTCTRL_MEMORY_MANAGEMENT_FAULT  (4U)
#define INTCTRL_BUS_FAULT                (5U)
#define INTCTRL_USAGE_FAULT              (6U)
#define INTCTRL_SVCALL                   (11U)
#define INTCTRL_DEBUG_MONITOR            (12U)
#define INTCTRL_PENDSV                   (14U)
#define INTCTRL_SYSTICK                  (15U)

/* Vector Number Of Interrupt Types */
#define INTCTRL_GPIO_PORTA_INTERRUPT                                 (16U)
#define INTCTRL_GPIO_PORTB_INTERRUPT                                 (17U)
#define INTCTRL_GPIO_PORTC_INTERRUPT                                 (18U)
#define INTCTRL_GPIO_PORTD_INTERRUPT                                 (19U)
#define INTCTRL_GPIO_PORTE_INTERRUPT                                 (20U)
#define INTCTRL_UART0_INTERRUPT                                      (21U)
#define INTCTRL_UART1_INTERRUPT                                      (22U)
#define INTCTRL_SSI0_INTERRUPT                                       (23U)
#define INTCTRL_I2C0_INTERRUPT 										 (24U)
#define INTCTRL_PWM0_FAULT_INTERRUPT								 (25U)
#define INTCTRL_PWM0_GENERATOR_0_INTERRUPT							 (26U)
#define INTCTRL_PWM0_GENERATOR_1_INTERRUPT							 (27U)
#define INTCTRL_PWM0_GENERATOR_2_INTERRUPT							 (28U)
#define INTCTRL_QEI0_INTERRUPT                                       (29U)
#define INTCTRL_ADC0_SEQUENCE_0_INTERRUPT							 (30U)
#define INTCTRL_ADC0_SEQUENCE_1_INTERRUPT							 (31U)
#define INTCTRL_ADC0_SEQUENCE_2_INTERRUPT							 (32U)
#define INTCTRL_ADC0_SEQUENCE_3_INTERRUPT 							 (33U)
#define INTCTRL_WATCHDOG_TIMER_0_AND_1_INTERRUPT					 (34U)
#define INTCTRL_16_32_BIT_TIMER_0_A_INTERRUPT  						 (35U)
#define INTCTRL_16_32_BIT_TIMER_0_B_INTERRUPT						 (36U)
#define INTCTRL_16_32_BIT_TIMER_1_A_INTERRUPT						 (37U)
#define INTCTRL_16_32_BIT_TIMER_1_B_INTERRUPT                      	 (38U)
#define INTCTRL_16_32_BIT_TIMER_2_A_INTERRUPT					     (39U)
#define INTCTRL_16_32_BIT_TIMER_2_B_INTERRUPT                        (40U)
#define INTCTRL_ANALOG_COMPARATOR_0_INTERRUPT						 (41U)
#define INTCTRL_ANALOG_COMPARATOR_1_INTERRUPT						 (42U)
#define INTCTRL_SYSTEM_CONTORL_INTERRUPT                             (44U)
#define INTCTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL_INTERRUPT    (45U)
#define INTCTRL_GPIO_PORTF_INTERRUPT								 (46U)
#define INTCTRL_UART2_INTERRUPT										 (49U)
#define INTCTRL_SSI1_INTERRUPT                                       (50U)
#define INTCTRL_16_32_BIT_TIMER_3_A_INTERRUPT						 (51U)
#define INTCTRL_16_32_BIT_TIMER_3_B_INTERRUPT						 (52U)
#define INTCTRL_I2C1_INTERRUPT									     (53U)
#define INTCTRL_QEI1_INTERRUPT                                       (54U)
#define INTCTRL_CAN0_INTERRUPT										 (55U)
#define INTCTRL_CAN1_INTERRUPT										 (56U)
#define INTCTRL_HIBERNATION_MODULE_INTERRUPT						 (59U)
#define INTCTRL_USB_INTERRUPT										 (60U)
#define INTCTRL_PWM_GENERATOR_3_INTERRUPT							 (61U)
#define INTCTRL_UDMA_SOFTWARE_INTERRUPT								 (62U)
#define INTCTRL_UDMA_ERROR_INTERRUPT								 (63U)
#define INTCTRL_ADC1_SEQUENCE_0_INTERRUPT							 (64U)
#define INTCTRL_ADC1_SEQUENCE_1_INTERRUPT							 (65U)
#define INTCTRL_ADC1_SEQUENCE_2_INTERRUPT							 (66U)
#define INTCTRL_ADC1_SEQUENCE_3_INTERRUPT							 (67U)
#define INTCTRL_SSI2_INTERRUPT                                       (73U)
#define INTCTRL_SSI3_INTERRUPT                                       (74U)
#define INTCTRL_UART3_INTERRUPT                                      (75U)
#define INTCTRL_UART4_INTERRUPT                                      (76U)
#define INTCTRL_UART5_INTERRUPT                                      (77U)
#define INTCTRL_UART6_INTERRUPT                                      (78U)
#define INTCTRL_UART7_INTERRUPT                                      (79U)
#define INTCTRL_I2C2_INTERRUPT                                       (84U)
#define INTCTRL_I2C3_INTERRUPT 									 	 (85U)
#define INTCTRL_16_32_BIT_TIMER_4_A_INTERRUPT						 (86U)
#define INTCTRL_16_32_BIT_TIMER_4_B_INTERRUPT						 (87U)
#define INTCTRL_16_32_BIT_TIMER_5_A_INTERRUPT						 (108U)
#define INTCTRL_16_32_BIT_TIMER_5_B_INTERRUPT						 (109U)
#define INTCTRL_32_64_BIT_TIMER_0_A_INTERRUPT						 (110U)
#define INTCTRL_32_64_BIT_TIMER_0_B_INTERRUPT						 (111U)
#define INTCTRL_32_64_BIT_TIMER_1_A_INTERRUPT						 (112U)
#define INTCTRL_32_64_BIT_TIMER_1_B_INTERRUPT						 (113U)
#define INTCTRL_32_64_BIT_TIMER_2_A_INTERRUPT						 (114U)
#define INTCTRL_32_64_BIT_TIMER_2_B_INTERRUPT						 (115U)
#define INTCTRL_32_64_BIT_TIMER_3_A_INTERRUPT						 (116U)
#define INTCTRL_32_64_BIT_TIMER_3_B_INTERRUPT						 (117U)
#define INTCTRL_32_64_BIT_TIMER_4_A_INTERRUPT						 (118U)
#define INTCTRL_32_64_BIT_TIMER_4_B_INTERRUPT						 (119U)
#define INTCTRL_32_64_BIT_TIMER_5_A_INTERRUPT						 (120U)
#define INTCTRL_32_64_BIT_TIMER_5_B_INTERRUPT						 (121U)
#define INTCTRL_SYSTEM_EXEPTION_INTERRUPT   						 (122U)
#define INTCTRL_PWM1_GENERATOR_1_INTERRUPT							 (150U)
#define INTCTRL_PWM1_GENERATOR_1_INTERRUPT							 (151U)
#define INTCTRL_PWM1_GENERATOR_2_INTERRUPT							 (152U)
#define INTCTRL_PWM1_GENERATOR_3_INTERRUPT							 (153U)
#define INTCTRL_PWM1_FAULT_INTERRUPT								 (154U)

/* Interrupt Group Priority Number */
#define INTCTRL_GROUP0	(0U)
#define INTCTRL_GROUP1	(1U)
#define INTCTRL_GROUP2	(2U)
#define INTCTRL_GROUP3	(3U)
#define INTCTRL_GROUP4	(4U)
#define INTCTRL_GROUP5	(5U)
#define INTCTRL_GROUP6	(6U)
#define INTCTRL_GROUP7	(7U)

/* Interrupt Sub Group Priority Number */
#define INTCTRL_SUBGROUP0	(0U)
#define INTCTRL_SUBGROUP1	(1U)
#define INTCTRL_SUBGROUP2	(2U)
#define INTCTRL_SUBGROUP3	(3U)
#define INTCTRL_SUBGROUP4	(4U)
#define INTCTRL_SUBGROUP5	(5U)
#define INTCTRL_SUBGROUP6	(6U)
#define INTCTRL_SUBGROUP7	(7U)

/* Fixed Group Priority Number */
#define RESET_GROUP_PRIORITY                     (-3)
#define NON_MASKABLE_INTERRUPT_GROUP_PRIORITY    (-2)
#define HARD_FAULT_GROUP_PRIORITY                (-1)

/* Fixed Sub-Group Priority Number */
#define RESET_SUP_GROUP_PRIORITY                     (-3)
#define NON_MASKABLE_INTERRUPT_SUP_GROUP_PRIORITY    (-2)
#define HARD_FAULT_SUP_GROUP_PRIORITY                (-1)

/* Write and Read(VECTKEY)Bits in order to change the bits in this register.*/
#define INTCTRL_VALUE_TO_WRITE_NUMBER  0x05FA
#define INTCTRL_VALUE_TO_READ_NUMBER   0xFA05

/* Shift Bit In Register (VECTKEY) & (PRIGROUP) */
#define APINT_VECTKEY_NUM  (16)
#define APINT_PRIGROUP_NUM  (8)

/* Interrupt Priority Levels Group And Sub-Group */
#define NVIC_PRIORITY_GROUPS_7_SUB_0                     0x4
#define NVIC_PRIORITY_GROUPS_0_SUB_7                     0x7
#define NVIC_PRIORITY_GROUPS_3_SUB_1                     0x5
#define NVIC_PRIORITY_GROUPS_1_SUB_3                     0x6

/* Macros for IntCtrl Status */
#define INTCTRL_INITIALIZED                (1U)
#define INTCTRL_NOT_INITIALIZED            (0U)

#define PRIX_INTA_NUM      (5)
#define PRIX_INTB_NUM      (13)
#define PRIX_INTC_NUM      (21)
#define PRIX_INTD_NUM      (29)

/* Enable Exceptions */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Disable Exceptions */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults */
#define Disable_Faults()       __asm("CPSID F") 

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")


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

 
#endif  /* INTCTRL_CFG.H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

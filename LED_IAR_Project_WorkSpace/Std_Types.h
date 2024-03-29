/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *       Module:  Common - Platform
 *
 *  Description:  General type definitions     
 *  
 *********************************************************************************************************************/
#ifndef STD_TYPES_H.H
#define STD_TYPES_H.H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define STD_HIGH        0x01U       /* Standard_HIGH */
#define STD_LOW         0x00U       /* Standard_LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard_ON */
#define STD_OFF         0x00U       /* Standard_OFF */

#define LOGIC_HIGH      (1u)
#define LOGIC_LOW       (0u)

#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8  Std_ReturnType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* STD_TYPES_H.H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


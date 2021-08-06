/*****************************************************************************
* Author(s):                                                                 *
*                                                                            *
* File:		T_Server.c                                                         *
*                                                                            *
* Description: Server-side code                                              *
*                                                                            *
*****************************************************************************/


/* Includes: ****************************************************************/

#include "T_Server.h"

/****************************************************************************/

/* Defines: *****************************************************************/
/****************************************************************************/

/* Typedefs: ****************************************************************/
/****************************************************************************/

/* Function Definitions: ****************************************************/
// Helper Functions

/*****************************************************************************
*                                                                            *
* Name:			  SokInit_Handlr()                                               *
* Purpose:    Handles the creation of a Socket                               *
* Parameters: None                                                           *  
* Returns:		Unsigned 16-bit integer                                        *
*                                                                            *
*****************************************************************************/

uint16_t	SokInit_Handlr(void)
{
  // Local Variables
  uint32_t                  hSocket;
  // Output
  printf("\n>>> Server-Side Socket Initialization >>>\n\n");
  // Socket System Call
  hSocket                 = socket(AF_INET, SOCK_STREAM, 0);
  // Output Validation
  printf("\n<<< Server-Side Socket Init Success <<<\n\n");
  // Function Return
  return                    hSocket;
}

// End SokInit_Handlr()
/****************************************************************************/


/*****************************************************************************
*                                                                            *
* Name:			  BindSrvSok_Handlr()                                            *
* Purpose:    Handles the binding of a Socket to the Server                  *
* Parameters: Unsigned 32-bit integer                                        *  
* Returns:		Unsigned 32-bit integer                                        *
*                                                                            *
*****************************************************************************/

uint32_t	BindSrvSok_Hndlr(uint32_t uSrvSok)
{
  // Local Variables
  uint32_t  retVal        = -1;
  uint32_t  clPort        = TEST_PORT;
  // sock_addr_in initialization
  S_SADDR   Srv           = {0};
  Srv.sin_family          = AF_INET;
  Srv.sin_addr.s_addr     = htonl(INADDR_ANY);
  Srv.sin_port            = htons(clPort);
  // Bind System Call
  retVal  = bind(uSrvSok, (S_SADDR *)&Srv, sizeof(Srv));
  // Function Return
  return retVal;    
}

// End BindSrvSok_Handlr() 
/****************************************************************************/


/****************************************************************************/
// End T_Server.c

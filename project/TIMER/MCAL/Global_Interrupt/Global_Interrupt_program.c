#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "Global_Interrupt_Register.h"
#include "Global_Interrupt_private.h"
#include "Global_Interrupt_interface.h"


void MGlobal_Interrupt_VoidEnable(void)
{
	SET_BIT(SREG,I);
}
void MGlobal_Interrupt_VoidDisable(void)
{
	CLR_BIT(SREG,I);
}

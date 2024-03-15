#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "STP_private.h"
#include "STP_config.h"
#include "STP_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

void S2P_vInit(void)
{
MGPIO_vSetMode(HSTP_SERIAL_DATA,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);

MGPIO_vSetMode(HSTP_SHIFT_CLOCK,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);

MGPIO_vSetMode(HSTP_STORAGE_CLOCK,MODE_OUTPUT);
MGPIO_vSetOutputMode(HSTP_SERIAL_DATA,OUTPUT_PUSHPULL,SPEED_LOW);
}

void S2P_vSendPulse(void)
{
MGPIO_vWritePin(HSTP_SHIFT_CLOCK,GPIO_HIGH);
MSYSYTICK_voidDelayUs(1);
MGPIO_vWritePin(HSTP_SHIFT_CLOCK,GPIO_LOW);
MSYSYTICK_voidDelayUs(1);

}

void S2P_vSendData(u16 Copy_u16Data)
{
	s8 Local_u8Iterator = 0 ;

	for(Local_u8Iterator = 15 ; Local_u8Iterator >= 0 ; Local_u8Iterator --  )
	{
		MGPIO_vWritePin(HSTP_SERIAL_DATA, GET_BIT(Copy_u16Data,Local_u8Iterator));
		S2P_vSendPulse();
	}
	/* Send Pulse To Storage Pin */
	MGPIO_vWritePin(HSTP_STORAGE_CLOCK,GPIO_HIGH);
	MSYSYTICK_voidDelayUs(1);
	MGPIO_vWritePin(HSTP_STORAGE_CLOCK,GPIO_LOW);
	MSYSYTICK_voidDelayUs(1);
}
void s2p_pinsEnable (void)
{

	MGPIO_vSetMode(PORT_A,PIN_8,MODE_OUTPUT);
		MGPIO_vSetOutputMode(PORT_A,PIN_8,OUTPUT_PUSHPULL,SPEED_LOW);

		MGPIO_vSetMode(PORT_A,PIN_9,MODE_OUTPUT);
		MGPIO_vSetOutputMode(PORT_A,PIN_9,OUTPUT_PUSHPULL,SPEED_LOW);

		MGPIO_vSetMode(PORT_A,PIN_10,MODE_OUTPUT);
		MGPIO_vSetOutputMode(PORT_A,PIN_10,OUTPUT_PUSHPULL,SPEED_LOW);
};

void S2P_PROGRAAME_1(void)
{

	S2P_vSendData(0xFE80);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDC4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFBFE);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF7FF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEFFF);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDFFE);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBFC4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F80);
	MSYSYTICK_voidDelayUs(20);


}

void S2P_PROGRAAME_2(void)
{

	S2P_vSendData(0xFE00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFDC4);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xFBA2);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xF791);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xEF89);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xDF86);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0xBF00);
	MSYSYTICK_voidDelayUs(20);
	S2P_vSendData(0x7F00);
	MSYSYTICK_voidDelayUs(20);
}

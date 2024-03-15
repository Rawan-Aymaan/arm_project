#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "DAC_interface.h"
#include "STP_interface.h"


#include "fanoos_img.h"
#include "Ramdan_karem_song.h"
#include "m3aak_albi_img.h"
#include "m3ak_albii_song.h"

void notificatin1(void);
void notificatin2(void);

u8 flag=0;
u8 stp_dac=0;
u8 pause_flag=0;

int main (void)
{
	MRCC_vInt();
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOA);
	MRCC_vEnable(RCC_AHB1,AHB1_GPIOB);
	MRCC_vEnable(RCC_APB2, APB2_SYSCFG);
	MRCC_vEnable(RCC_APB2,APB2_SPI1);

	//// TFT PINS /////
	TFT_PinsEnable();

	///// switches PIN ////
	MGPIO_vSetMode(PORT_A, PIN_0, MODE_INPUT);
	MGPIO_vSetInputMode(PORT_A, PIN_0, INPUT_PULLUP);

	MGPIO_vSetMode(PORT_A, PIN_1, MODE_INPUT);
	MGPIO_vSetInputMode(PORT_A , PIN_1, INPUT_PULLUP);

	//  DAC PINS //
	HR2RDAC_vInit();

	//S2P PINS //
	s2p_pinsEnable();

	NVIC_VoidSetInterruptGroupMode(Group16Sub0);

	NVIC_VoidSetInterruptPriority(6,0,0);
	NVIC_VoidSetInterruptPriority(7,1,0);

	NVIC_vEnable(6);
	NVIC_vEnable(7);


	SPI1_voidInit();
	MSYSYTICK_voidInit();
	TFT_voidvInit();
	S2P_vInit();


	////// intrrupts ////
	MEXTI_voidInerruptSetPort(EXTI_LineZero,PORT_A);
	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero,EXTI_Enable);

	MEXTI_voidInerruptSetPort(EXTI_LineOne,PORT_A);
	MEXTI_voidInterruptTrigger(EXTI_LineOne,EXTI_Falling);
	MEXTI_voidInterruptEnableDisable(EXTI_LineOne,EXTI_Enable);

	MEXTI0_voidCallBack(notificatin1);
	MEXTI1_voidCallBack(notificatin2);





	while (1)
		{
		switch (flag)
				{
				case 1:
					stp_dac=1;
					pause_flag=1;
					TFT_voidDisplay(fanoos_img);
					HR2RDAC_vSetData(Ramdan_Kareem_raw,48000,&stp_dac,&pause_flag);
					break;

				case 2:
					stp_dac=2;
					pause_flag=1;
					TFT_voidDisplay(m3aak_albi_img);
					HR2RDAC_vSetData(m3ak_albii_raw,40124,&stp_dac,&pause_flag);
					break;
				default:
				asm("NOP");
				break;
			}

		}

}


void notificatin1(void)
{
	flag =1;
	pause_flag=0;


}
void notificatin2(void)
{
	flag=2;
	pause_flag=0;
}


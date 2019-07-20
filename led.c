#include"uart.h"
#include"PLL.h"
void SystemInit(){}
	
int  main(){
	uint8_t Str[50];
	uint32_t delay;
  SYSCTL_RCGCGPIO_R  |= (1<<5);
	delay = 1;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R= 0x1F;
	GPIO_PORTF_AFSEL_R=0;
	GPIO_PORTF_PCTL_R=0;
  GPIO_PORTF_AMSEL_R=0;
	GPIO_PORTF_DEN_R = 0x1F;
	GPIO_PORTF_DIR_R |= 0xE; 
  PLL_Init();
	UART0_Init();
	
	while(1)
	{
   UART_receiveString(Str);
		if(Str[0]=='r'&&Str[1]=='e'&&Str[2]=='d'&&Str[3]=='o'&&Str[4]=='n')
		{
				GPIO_PORTF_DATA_R = 0x2;			
		}
		else if(Str[0]=='g'&&Str[1]=='r'&&Str[2]=='e'&&Str[3]=='e'&&Str[4]=='n'&&Str[5]=='o'&&Str[6]=='n')
		{
				GPIO_PORTF_DATA_R = 0x8;			
		}
		else if(Str[0]=='b'&&Str[1]=='l'&&Str[2]=='u'&&Str[3]=='e'&&Str[4]=='o'&&Str[5]=='n')
		{
				GPIO_PORTF_DATA_R = 0x4;			
		}
		else
		{
				GPIO_PORTF_DATA_R &= ~(0x07);			

		} 
	}
}
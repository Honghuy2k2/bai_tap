
#include"stdio.h"
#include "sys.h"
#include "delay.h"
#include <stdlib.h>
#include <stdio.h>



#define SDA_IN()  {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=8<<4;}	//PB9IN
#define SDA_OUT() {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=3<<4;} //PB9OUT
 

#define I2C_SCL    PBout(8) //SCL
#define I2C_SDA    PBout(9) //SDA	 
#define READ_SDA   PBin(9)  //SDA IN


void I2C_init(void);                			 
void I2C_Start(void);				
void I2C_Stop(void);	  			
void I2C_Send_Byte(u8 txd);		
uint8_t I2C_Read_Byte(unsigned char ack);
uint8_t I2C_Wait_Ack(void); 				
void I2C_Ack(void);					
void I2C_NAck(void);


u8 scans_IIC( u8 add)	{
	
	I2C_Start();	
	I2C_Send_Byte(add|0);
	if(I2C_Wait_Ack()) {I2C_Stop(); return 1;}
	
	return 0;
}
 int main(void)
 {	
	 uint8_t add=0, err=0;
	 delay_init();
  while(1)
	{
	
		for(add=1;add<255;add++)
		{
			err=scans_IIC(add);
			if(err==0)
      {
			        printf("ADD= 0x%X\r\n",add);
			}
		}		
			delay_ms(1500);
	}
 }


void I2C_init(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;			    //LED0-->PB.5 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//GPIO_Mode_Out_PP; 	 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //GPIOB.5
	I2C_SCL=1;
	I2C_SDA =1;
}

/*
* Function: Start
* Description: This function pulse configuration
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   No
*/

void I2C_Start(void){
	SDA_OUT();
	I2C_SCL=1;
	I2C_SDA =1;
	delay_us(4);
	I2C_SDA =0;
	delay_us(4);
	I2C_SCL=0;	
}

/*
* Function: Stop
* Description: This function pulse configuration
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   No
*/

void I2C_Stop(void){	
	SDA_OUT();
	I2C_SCL=0;
	I2C_SDA =0;
	delay_us(4);
	I2C_SDA =1;
	I2C_SCL=1;
	delay_us(4);		
}

/*
* Function: I2C_Send_Byte
* Description: This function send bits
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   No
*/

void I2C_Send_Byte(uint8_t txd){//11111111&10000000
	int i=0;
	SDA_OUT();
	I2C_SCL=0;
	for(i=0;i<8;i++){
		I2C_SDA=(txd&0x80)>>7;
		txd<<=1;
		delay_us(2);
		I2C_SCL=1;
		delay_us(2);
		I2C_SCL=0;
		
	}
	
}

/*
* Function: I2C_Ack
* Description: This function pulse configuration
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   No
*/

void I2C_Ack(void){
	I2C_SCL=0;
	SDA_OUT();
	I2C_SDA=0;
	delay_us(2);
	I2C_SCL=1;
	delay_us(2);
	I2C_SCL=0;
}				

/*
* Function: I2C_NAck
* Description: This function pulse configuration
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   No
*/
void I2C_NAck(void){
	I2C_SCL=0;
	SDA_OUT();
	I2C_SDA=1;
	delay_us(2);
	I2C_SCL=1;
	delay_us(2);
	I2C_SCL=0;
}	

/*
* Function: I2C_Read_Byte
* Description: This function send bits
* Input:
*  I2C_SCL a port
*	 I2C_SDA a port
* Output:
*   returns bit reads
*/

uint8_t I2C_Read_Byte(unsigned char ack){
	int i=0;
	uint8_t rec=0;
	SDA_IN();
	for(i=0;i<8;i++){//11111111
		I2C_SCL=0;
		delay_us(2);
		I2C_SCL=1;
		delay_us(2);
		rec<<=1;
		if(I2C_SDA) rec++;
	}
	if(!ack){
		I2C_Ack();
	}
		else{
		I2C_NAck();	
		}
}

uint8_t I2C_Wait_Ack(void){
	uint8_t time=0;
	SDA_IN();
	I2C_SDA=1;delay_us(1);
	I2C_SCL=1;delay_us(1);
	while(READ_SDA){
		time++;
		if(time>250) {I2C_Stop(); return 1;}
	}
	I2C_SCL=0;
	return 0; 
}

/*
===============================================================================
 Name        : 10_Day27_22092021_GPIO010.c

 Description : 4 seven segment display from 0000 to 9999 with a delay
 	 	 	   Data Pins PORT 1.19 to P1.26
 	 	 	   Control Pins PORT 0.4 to 0.7

 
 Layered Architecture used for this project
 ************************************
 Application layer-09_Day26_210921_GPIO009.c
 ************************************
 Board layer - sevenseg.c/.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "sevenseg.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define MAXTIMEOUT 0xFFFF
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{

	vSevenSegInitialize();
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	uint8_t  segarray[4]={0,0,0,0};
	uint8_t  segno=0;
	uint16_t num=1234;
	uint32_t delaycount=0;
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

     vSevenSegDisplay(segno, segarray[segno]);
     segno++;
     if(segno>3)
    	 segno=0;

 	  delaycount++;
 	  if(delaycount>MAXTIMEOUT)
 	  {
 		  delaycount=0;
		  num++;
		   if(num>9999)
		  		  num=0;

		  segarray[3]=num%10;
		  segarray[2]=(num/10)%10;
		  segarray[1]=(num/100)%10;
		  segarray[0]=(num/1000);
 	  }


  }
  /* End of Application entry point */
}





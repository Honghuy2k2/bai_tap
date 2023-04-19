
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"

#define sizeofBuff 20

char spiMasterTX= 1;
uint8_t RX_Index=0;

#define SCK    5    // ch�n SCK
#define MOSI   7    // Ch�n MOSI
#define SS     4    // Ch�n SS
#define MISO   6    // ch�n MISO



void SPI_Soft_init();// chuong tr�nh khoi tao SPI
void Clock();// chuong tr�nh tao 1 xung clock
void SPI_Soft_Transmit(uint8_t mData);// chuong tr�nh gui 1 byte
uint8_t SPI_Soft_Receive();// chuong tr�nh nhan ve 1 byte


 static void SystemClock_Config(void);


void SPI_init()
{
	HAL_GPIO_WritePin(GPIOA,SCK, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,MOSI, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,SS, GPIO_PIN_SET);
}

void Clock(){
  HAL_GPIO_WritePin(GPIOA,SCK, GPIO_PIN_SET);
  HAL_Delay(100);
  HAL_GPIO_WritePin(GPIOA,SCK, GPIO_PIN_RESET);
   HAL_Delay(100);
}

void SPI_Soft_Transmit(uint8_t mData){ 
  uint8_t i = 0;  
  HAL_GPIO_WritePin(GPIOA,SS,GPIO_PIN_RESET);   
	
  for(i = 0; i < 8; i++){// dua bit can truyen l�n ch�n MOSI
 		if( (mData&0x80)!=0)
     HAL_GPIO_WritePin(GPIOA,MOSI,GPIO_PIN_SET);   
    else
     HAL_GPIO_WritePin(GPIOA,MOSI,GPIO_PIN_RESET);    
    Clock(); // ph�t 1 xung clock gui du lieu di   
    mData=mData<<1; // dich du lieu can gui l�n 1 bits   
  }  
  HAL_GPIO_WritePin(GPIOA,SS,GPIO_PIN_SET);; //�� gui xong,dua ch�n SS l�n muc 1
}



uint8_t SPI_Soft_Receive(){  
  uint8_t _data=0x00, i=0;  
  while(i<8){     
    _data = _data<<1;       // dich du lieu l�n 1 bit     
    _data = _data | MISO;    //doc ch�n MISO     
    Clock();                // ph�t mot xung clock de doc bit tiep theo  
  }   
  return _data;             // tra ve du lieu doc duoc 
}

int main(void)
{
 
  HAL_Init();
  SystemClock_Config();
   SPI_init();
   Clock();

  while (1)
  {
    /* USER CODE END WHILE */
		HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
	  SPI_Soft_Transmit(spiMasterTX );
	  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
	  spiMasterTX ++;
		HAL_Delay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 32;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : CS_Pin */
  GPIO_InitStruct.Pin = CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

void SystemClock_Config(void);

/* USER CODE BEGIN 0 */
int dem ;
uint8_t TTnut;
/* USER CODE END 0 */

int main(void)
{

  HAL_Init();

  SystemClock_Config();


  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	/*---------CACH 1----------*/
//	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
//			while (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1);
//			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
//			HAL_Delay(50);
//		}

	/*---------CACH 2----------*/
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
			TTnut =1;
			if(TTnut ==1) {
				HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
				HAL_Delay(200);
				TTnut =0;
			}
		}
		else TTnut =0;
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

void Error_Handler(void)
{

  __disable_irq();
  while (1)
  {
  }
  
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif /* USE_FULL_ASSERT */

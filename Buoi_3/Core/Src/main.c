
#include "main.h"
#include "gpio.h"

/* USER CODE BEGIN PV */
	int chonled=0;
	int tt=0;
	int tt1=0;
	uint32_t x,z;
	uint8_t sang,toi;
	uint8_t sang1,toi1;
	int mode=1;
	int check;
/* USER CODE END PV */

void SystemClock_Config(void);

/* USER CODE BEGIN 0 */
void chonled1(uint32_t delay_on,uint32_t delay_off){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_Delay(delay_on);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_Delay(delay_off);
}
void chonled2(uint32_t delay_on,uint32_t delay_off){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(delay_on);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_Delay(delay_off);
}
void checkmode(void) {
	if(mode==1){
		if(chonled ==0) {
			if(toi <10) chonled1(sang,toi);
			if(toi ==10) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
		}
		if(chonled ==1) {
			if(toi1 <10) chonled2(sang1,toi1);
			if(toi1 ==10) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
		}
		if(chonled ==2){
			if(toi <10) chonled1(sang,toi);
			if(toi ==10) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
			if(toi1 <10) chonled2(sang1,toi1);
			if(toi1 ==10) HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
		}
	}
	else{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,0);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,0);
	}
}
void dieuchinh(void){
	if(chonled ==0){
		if(tt==0){
			if(toi>0) toi=toi-2;
				sang=sang+2;
			if((sang ==4||sang==6) && toi == 8){
				sang=0;
				toi=10;
			}
			if(sang ==2 && toi == 10){
				sang=0;
				toi=10;
			}
			if(sang==7) sang =8;
			if(toi ==3) toi =2;
			if(sang>10 && toi==0) {
					sang=10;
					toi=0;
				if(check==0){
					sang=10;
					toi=0;
				}
				if (check!=0) tt=1;	
			}
		}
			
		if(tt==1){
			toi=toi+2;
			if(sang>0) sang=sang-2;
			if(toi==7) toi =8;
			if(sang ==3) sang =2;
			if(toi>=10 && sang==0) {
				toi=10;
				sang=0;
				if(check==0){
					toi=10;
					sang=0;
				}
				if (check!=0) tt=0;	
			}
		}
	}
	if(chonled ==1){
		if(tt1==0){
			if(toi1>0) toi1=toi1-2;
				sang1=sang1+2;
			if((sang1 ==4||sang1==6) && toi1 == 8){
				sang1=0;
				toi1=10;
			}
			if(sang1 ==2 && toi1 == 10){
				sang1=0;
				toi1=10;
			}
			if(sang1==7) sang1 =8;
			if(toi1 ==3) toi1 =2;
			if(sang1>10 && toi1==0) {
					sang1=10;
					toi1=0;
				if(check==0){
					sang1=10;
					toi1=0;
				}
				if (check!=0) tt1=1;	
			}
		}
		if(tt1==1){
			toi1=toi1+2;
			if(sang1>0) sang1=sang1-2;
			if(toi1==7) toi1 =8;
			if(sang1 ==3) sang1 =2;
			if(toi1>=10 && sang1==0) {
				toi1=10;
				sang1=0;
				if(check==0){
					toi1=10;
					sang1=0;
				}
				if (check!=0) tt1=0;	
			}
		}
	}
	if(chonled ==2){
		if(tt==0){
			if(toi>0) toi=toi-2;
				sang=sang+2;
			if((sang ==4||sang==6) && toi == 8){
				sang=0;
				toi=10;
			}
			if(sang ==2 && toi == 10){
				sang=0;
				toi=10;
			}
			if(sang==7) sang =8;
			if(toi ==3) toi =2;
			if(sang>10 && toi==0) {
					sang=10;
					toi=0;
				if(check==0){
					sang=10;
					toi=0;
				}
				if (check!=0) tt=1;	
			}
		}
		if(tt1==0){
			if(toi1>0) toi1=toi1-2;
				sang1=sang1+2;
			if((sang1 ==4||sang1==6) && toi1 == 8){
				sang1=0;
				toi1=10;
			}
			if(sang1 ==2 && toi1 == 10){
				sang1=0;
				toi1=10;
			}
			if(sang1==7) sang1 =8;
			if(toi1 ==3) toi1 =2;
			if(sang1>10 && toi1==0) {
					sang1=10;
					toi1=0;
				if(check==0){
					sang1=10;
					toi1=0;
				}
				if (check!=0) tt1=1;	
			}
		}
		if(tt==1){
			toi=toi+2;
			if(sang>0) sang=sang-2;
			if(toi==7) toi =8;
			if(sang ==3) sang =2;
			if(toi>=10 && sang==0) {
				toi=10;
				sang=0;
				if(check==0){
					toi=10;
					sang=0;
				}
				if (check!=0) tt=0;	
			}
		}
		if(tt1==1){
			toi1=toi1+2;
			if(sang1>0) sang1=sang1-2;
			if(toi1==7) toi1 =8;
			if(sang1 ==3) sang1 =2;
			if(toi1>=10 && sang1==0) {
				toi1=10;
				sang1=0;
				if(check==0){
					toi1=10;
					sang1=0;
				}
				if (check!=0) tt1=0;	
			}
		} 
	}
}

/* USER CODE END 0 */
int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	sang=5;
	toi=5;
	sang1=5;
	toi1=5;
  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {	
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1){
			checkmode();
			while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1){
				x++;
				checkmode();
			}
		}
		if(x>0&&x<30){
			chonled++ ;
			if(chonled>2) chonled =0;
			x=0;
		}
		if(x>30){
			mode =!mode;
			x=0;
		}
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
			while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
				z++;
				checkmode();
				if(z>45) {
					checkmode();
					dieuchinh();
					check=0;
					z=0;
				}
			}
			checkmode();
		}
		if(z>3&&z<=45){
			dieuchinh();
			if(toi >=10) HAL_Delay(20);
			
			checkmode();
			z=0;
		}
		check=2;
		if(z>=0 && z<=3){
			checkmode();
		}
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

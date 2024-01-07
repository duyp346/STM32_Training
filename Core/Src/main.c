
#include "main.h"
#include "i2c.h"
#include "gpio.h"
#include "lib_lcd.h"
#define DS1307_ADDRESS 0xd0

void SystemClock_Config(void);

uint8_t decToBcd(int val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}

int bcdToDec(uint8_t val)
{
  return (int)( (val/16*10) + (val%16) );
}
typedef struct
	{
	uint8_t giay;
	uint8_t phut;
	uint8_t gio;
	uint8_t thu;
	uint8_t ngay;
	uint8_t thang;
	uint8_t nam;
	
} ThoiGian;
ThoiGian time;
void Dat_thoigian (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
{
	uint8_t set_time[7];
	set_time[0] = decToBcd(sec);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(hour);
	set_time[3] = decToBcd(dow);
	set_time[4] = decToBcd(dom);
	set_time[5] = decToBcd(month);
	set_time[6] = decToBcd(year);

	HAL_I2C_Mem_Write(&hi2c1, DS1307_ADDRESS, 0x00, 1, set_time, 7, 10);
}
void docgiatri(void)
{
	uint8_t get_time[7];
	HAL_I2C_Mem_Read(&hi2c1, DS1307_ADDRESS, 0x00, 1, get_time, 7, 10);
	time.giay = bcdToDec(get_time[0]);
	time.phut = bcdToDec(get_time[1]);
	time.gio = bcdToDec(get_time[2]);
	time.thu = bcdToDec(get_time[3]);
	time.ngay = bcdToDec(get_time[4]);
	time.thang = bcdToDec(get_time[5]);
	time.nam = bcdToDec(get_time[6]);
}

int main(void)
{

  HAL_Init();

  SystemClock_Config();


  MX_GPIO_Init();
  MX_I2C1_Init();
Dat_thoigian(00,19,23,2,7,1,24);
  
  while (1)
  {
		docgiatri();
  }
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

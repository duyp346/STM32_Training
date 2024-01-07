
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
 extern int check;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId task2Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void delay(uint32_t delay_on,uint32_t delay_off){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_Delay(delay_on);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_Delay(delay_off);
}
void delay2(uint32_t delay_on,uint32_t delay_off){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_Delay(delay_on);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_Delay(delay_off);
}
void mode1(){
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			delay(i,20-i);
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			delay(20-i,i);
		}
	}		
}
void mode2(){
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			delay2(i,20-i);
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			delay2(20-i,i);
		}
	}		
}
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

void MX_FREERTOS_Init(void) {

  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityAboveNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of task2 */
  osThreadDef(task2, StartTask02, osPriorityIdle, 0, 128);
  task2Handle = osThreadCreate(osThread(task2), NULL);
	


  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */

/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		if(check==0) HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);
		else HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
    osDelay(500);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */

/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{

  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
		if(check==0) {
			if(check!=0) break;
			mode2();
	}
		else {
			if(check!=1) break;
			mode1();
		}
// osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

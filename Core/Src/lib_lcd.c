#include "lib_lcd.h"

void blink_led(int n){
	for(int i=0;i<n;i++){
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12|GPIO_PIN_13);
		HAL_Delay(200);
	}
}

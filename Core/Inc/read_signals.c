 #include "read_signals.h"





//struct signal_struct signal;

void signal_read(signal_struct* signal){
	//signal->clamp_switch_close_1	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5); //this has problems
	//signal->clamp_switch_close_2 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6); //this has problems

	signal->clamp_switch_open_1 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
	signal->clamp_switch_close_1 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2); //open_2
}

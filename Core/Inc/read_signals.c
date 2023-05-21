 #include "read_signals.h"





//struct signal_struct signal;

signal_struct signal_read(){
	static signal_struct signal;
	signal.clamp_switch_close_1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
	signal.clamp_switch_close_2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
	signal.clamp_switch_open_1 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
	signal.clamp_switch_open_2 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);

	return signal;
}

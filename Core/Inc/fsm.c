#include "fsm.h"
#include "addons.h"




extern eSystemState fsm_state_change(eSystemState state,
		bool* req_clamp_open,
		bool* req_EM_open,
		uint8_t flag_action_result)
{
	switch (state){
		case Idle_State:


			if(*req_clamp_open){
				*req_clamp_open = false;
				state = Clamp_Opening_State;
			}
			else if(*req_EM_open){
				*req_EM_open = false;
				state = EM_Open_State;
			}
			break;
		case Clamp_Opening_State:
			if(flag_action_result == ACTION_OK){
				state = Clamp_Closing_State;
			}
			break;

		case Clamp_Closing_State:
			if(flag_action_result == ACTION_OK){
				state = Idle_State;
			}
			break;
		case EM_Open_State:
			if(flag_action_result == ACTION_OK){
				state = Idle_State;
			}
			break;
		case Error_State:
			//indicate problem using LED
			break;
	}
	return state;
}


extern uint8_t fsm_state_action(eSystemState state, signal_struct signal, TIM_HandleTypeDef* htim2, TIM_HandleTypeDef* htim1)
{
	uint8_t action_result;
	action_result = ACTION_NOK;
	static uint16_t counter=0;
	switch (state){
		case Idle_State:

			break;
		case Clamp_Opening_State:

			//set PWM motor for open clamp
			  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

			if(counter >=3000){
				counter = 0;
				//stop PWM
				//HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
				//action_result = ACTION_ERROR;  //correct line
				action_result = ACTION_OK; //fake line for debug purpose
			}


			if(signal.clamp_switch_close_1 && signal.clamp_switch_close_2){
				//stop PWM
				//HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
				//action_result = ACTION_OK; //fake
			}


			counter ++;
			break;

		case Clamp_Closing_State:

			//set PWM motor for open clamp
			//HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);

			if(counter >=3000){
				counter = 0;
				//stop PWM
				//HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
				//action_result = ACTION_ERROR;  //correct line
				action_result = ACTION_OK; //fake line for debug purpose
				//stop PWM
			}

				//set PWM motor for open clamp
			if(signal.clamp_switch_open_1 && signal.clamp_switch_open_2){
				//action_result = ACTION_OK; //fake
				//stop PWM
				//HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
			}

			counter ++;

			break;
		case EM_Open_State:

			//setp pin to open EM

			if(counter >= 1000){
				//setp pin to open EM
				action_result = ACTION_OK;
			}


			break;
		case Error_State:
			break;
	}
	return action_result;
}

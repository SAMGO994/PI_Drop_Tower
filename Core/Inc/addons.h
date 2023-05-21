/*
 * addons.h
 *
 *  Created on: 7 mag 2023
 *      Author: samue
 */

#ifndef INC_ADDONS_H_
#define INC_ADDONS_H_

#define SIZE_DATA 6

//defines for the action result
#define ACTION_OK 1
#define ACTION_NOK 2
#define ACTION_ERROR 3


#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef enum
{
    Idle_State,
    Clamp_Opening_State,
    Error_State,
	EM_Open_State,
	Clamp_Closing_State

} eSystemState;


typedef struct
{
	bool clamp_switch_open_1;
	bool clamp_switch_open_2;
	bool clamp_switch_close_1;
	bool clamp_switch_close_2;
}signal_struct;

struct flag_struct
{
	bool Clamp_open;
	bool EM_open;
};

#endif /* INC_ADDONS_H_ */

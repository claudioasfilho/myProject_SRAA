/* 
 * File:   Scheduler.h
 * Author: C13998
 *
 * Created on March 31, 2015, 11:12 AM
 */

#ifndef SCHEDULER_H
#define	SCHEDULER_H

#include <SI_EFM8BB3_Register_Enums.h>                  // SFR declarations

/*typedef union
        {

	struct{
	  	  bit		Unused0;
	  	  bit		Unused1;
	  	  bit		Unused2;
	  	  bit		Unused3;
	  	  bit		Unused4;
    	  bit		Enabled;         // Is the task enabled or not?
    	  bit		Finished;
    	  bit		Status;
	}bits;

	uint8_t all;
    } OBJFLAGS;
*/

typedef enum
    {
        PID_TASK=0,
        DACOUTPUT_TASK,
        MAX_TASKS
    } TASKSID;




typedef struct
{
    uint16_t period;                    // How Often the function gets called
    uint16_t counter;                   // Local Counter incremented by the scheduler. Once "counter" matches "period" Function is executed  holds how many ticks
    uint8_t  Enabled;                     //Flags that will be used by the Scheduler and System in general
    void (*function)(void);             // Function pointer for task

} SYSTASKS;


void Scheduler_CallBack(void);

/*Functions used by the objects*/
void Update_task_period ( uint16_t period , TASKSID tasknum);
//void Update_task_Flags ( OBJFLAGS Flags , TASKSID tasknum);

#endif	/* SCHEDULER_H */


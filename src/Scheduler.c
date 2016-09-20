
#include <SI_EFM8BB3_Register_Enums.h>                  // SFR declarations

#include "PID.h"
#include "Scheduler.h"

/* Declaration of all the Tasks that will be performed by the scheduler *
 * All Tasks are disabled and period is set to 10 ticks by default * */
//void Pot_Handler(void)


xdata SYSTASKS tasks[MAX_TASKS] =
{
    /*
     * period,  counter,    Enabled,  Function Pointer (To Object Handler that requires constant threat) */

	{   39,         0,      1,      &DimmerCounterHandler},
    {   2,         0,      1,      &DACOutputHandler},
    {   5,         0,      1,      &PIDHandler},


};


/*This Function is called by the objects and update the flags*/

/*void Update_task_Flags ( OBJFLAGS Flags , TASKSID tasknum)
{
    tasks[tasknum].Flags = Flags;
}*/

/*This Function is called by the objects and update the period, which is how often every task should run*/
void Update_task_period ( uint16_t period , TASKSID tasknum)
{
    tasks[tasknum].period = period;
}

/*This is the Scheduler itself. It is called by the Timer 2 interrupt and then it jumps on the tasks
 * once the Task period matches. The priority is defined by the way they are listed on the TASKSID
 * enumeration. */


void Scheduler_CallBack(void)
{
static TASKSID taskCounter;

 for (taskCounter = 0; taskCounter < MAX_TASKS; taskCounter++)
    {
        if (tasks[taskCounter].Enabled == 1)
        {
            if (tasks[taskCounter].counter++ == tasks[taskCounter].period)
                 {
                     (tasks[taskCounter].function)();
                     tasks[taskCounter].counter=0;
                 }
        }
 
    }



   // Buttons_Handler();
}
/**
  End of File
*/

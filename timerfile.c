  
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int alarms = 0;
void incre_alarm() 
{
  alarms += 1;
}

void handler(int signum)
{ // SIGINT handler
  printf("\nTotal alarms occured: %d\n", alarms);
  printf("Hence, the program was executed for %d seconds.\n",alarms);
  exit(0);
}

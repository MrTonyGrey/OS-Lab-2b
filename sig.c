/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "timer.h"

void hand(int signum)
{ //signal handler
  printf("Hello World!\n");
  incre_alarm();
}

int main(int argc, char * argv[])
{
  signal(SIGINT,handler); // Register handler to handle SIGINT.
  signal(SIGALRM,hand); // Register handler to handle SIGALRM.
  while(1){
    alarm(1); // Schedule a SIGALRM for 1 second.
    sleep(1);
    printf("Turing was right!\n");
  }
  return 0; // Never reached.
}

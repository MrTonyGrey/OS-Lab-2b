/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int hold = 0;

void handler(int signum)
{ 
  printf("Hello World!\n");
  hold = 1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  while(1){
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!hold);
    printf("Turing was right!\n");
    hold=0;
  };
  
  //busy wait for signal to be delivered
  return 0; //never reached
}

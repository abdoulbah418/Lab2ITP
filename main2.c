#include  <stdio.h>
#include  <sys/types.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <time.h>

#define   MAX_COUNT  200

void ChildProcess(void);                /* child process prototype  */
void ParentProcess(void);               /* parent process prototype */

int main(void)
{
  pid_t  pid;
  int i;
  for(i = 0; i < 2; i++){
    pid = fork();
    if (pid == 0) {
      ChildProcess();
    }      
    else if (pid < 0){
      printf("fork error");
    }          
  }     
  ParentProcess();

  return 0;
}

void  ChildProcess()
{
  int randnum;
  printf("child process %d going to sleep for 1 second\n" , getpid());
  srand(getpid());
  randnum = rand() % 10; 
  sleep(randnum + 1);
  printf("child process %d is running\n", getpid());
  int a, b, c;
  c = a + b;
  sleep(0.5);
  exit(0);
}

void  ParentProcess(void)
{
  int i, pid;
  for (i = 0; i < 2; i++)
  {
    pid = wait(0);
    printf("child process %d has completed\n", pid);
  }
}

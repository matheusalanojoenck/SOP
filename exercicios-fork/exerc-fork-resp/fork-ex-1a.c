#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
     pid_t f1, f2, f3;
     
     printf("Processo principal (PID=%u)\n", getpid());
     printf("A (PID=%u, pai=%u)\n", getpid(), getppid());
     f1 = fork();
     if (f1 == 0) {
	  printf("B (PID=%u, pai=%u)\n", getpid(), getppid());
     } else {
	  f2 = fork();
	  if (f2 == 0) {
	       printf("C (PID=%u, pai=%u)\n", getpid(), getppid());
	  } else {
	       f3 = fork();
	       if (f3 == 0)
		    printf("D (PID=%u, pai=%u)\n", getpid(), getppid());
	  }
     }
     sleep(60);
     return 0;
}

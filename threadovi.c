#include <stdio.h>
#include <sys/types.h>

#define MAX_COUNT 200

void main() {
	pid_t pid;
	
	pid = fork();
	
	if (pid == 0) {
		printf("(child) My parent pid is: %d\n", getppid());
		printf("(child) pid je: %d\n", getpid());
		//int   i;
		//for (i = 1; i <= MAX_COUNT; i++)
          //printf("   This line is from child, value = %d\n", i);
		//printf("   *** Child process is done ***\n");
	} else {
		printf("(parent) my parent pid is: %d\n", getppid());
		printf("(parent) pid deteta je: %d\n", pid);
		printf("(parent) pid je: %d\n", getpid());
		//int   i;
		//for (i = 1; i <= MAX_COUNT; i++)
          //printf("This line is from parent, value = %d\n", i);
		//printf("*** Parent is done ***\n");
	}
	
}
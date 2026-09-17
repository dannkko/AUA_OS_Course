#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int main() {
	int pid = fork();
	
	if (pid == -1) {
		perror ("fork");
		return -1;
	}
	if (!pid)		// Child 1 
		execl("/usr/bin/ls", "ls", NULL);
	else {			// Parent
		wait(NULL);
		pid = fork();
		if (pid == -1) {
			perror("fork");
			return -1;
		}
		if (!pid)	// Child 2
			execl("/usr/bin/date", "date", NULL);
		else {
			wait(NULL);
			printf("Parent process done\n");
			return 0;
		}
	}
}

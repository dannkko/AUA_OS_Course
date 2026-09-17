#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

int main() {
	int pid = fork();
	if (!pid)	// Child process
		execl("/usr/bin/ls", "ls", NULL);
	else {		// Parent process
		wait(NULL);
		printf("Parent process done\n");
		return 0;
	}
}

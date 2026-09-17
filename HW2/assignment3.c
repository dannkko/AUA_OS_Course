#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>

int main() {
	int pid = fork();
	if (pid == -1)
		perror("fork");
	if (!pid)	// Child process
		execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);
	else {		// Parent process
		wait(NULL);
		printf("Parent process done\n");
		return 0;
	}
}

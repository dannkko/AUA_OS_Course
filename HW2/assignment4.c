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
	if (!pid)	// Child process
		execl("/usr/bin/grep", "grep", "-o", "main", "test.txt", NULL);
	else {		// Parent process
		wait(NULL);
		printf("Parent process completed\n");
		return 0;
	}
}

#include <stdio.h>
#include "stdlib.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(1);
	}

	if (pid == 0) {
		exit(0);
	}
	// Uncomment to avoid 'ZOMBIE' state
//	wait(NULL); 
	sleep(5);
	exit(0);
}

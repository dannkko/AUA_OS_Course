#include <stdio.h>
#include "stdlib.h"
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(1);
	}

	if (pid == 0) {
		printf("Child's PID: %d\n", getpid());
		exit(0);
	}
	else {
		printf("Parent's PID: %d\n", getpid());
		exit(0);
	}
}	

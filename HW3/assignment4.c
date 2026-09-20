#include <stdio.h>
#include "stdlib.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void print_child_status(pid_t pid, int status) {
	printf("Child with PID %d exit status: ", pid);
	if (WIFEXITED(status))
		printf("Normal termination with exit status = %d\n", WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		printf("Killed by signal = %d%s\n", WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
	if (WIFSTOPPED(status))
		printf("Stopped by signal = %d\n", WSTOPSIG(status));
	if (WIFCONTINUED(status))
		printf("Continued\n");
}

int main() {
	pid_t pid = fork();
	int status;

	if (pid < 0) {
		perror("Fork failed");
		exit(1);
	}

	if (pid == 0) {
		exit(2);
	}

	waitpid(pid, &status, 0);
	print_child_status(pid, status);
	pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(1);
	}

	if (pid == 0) {
		exit(3);
	}

	waitpid(pid, &status, 0);
	print_child_status(pid, status);
	exit(0);
}

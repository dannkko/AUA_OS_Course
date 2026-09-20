#include <stdio.h>
#include "stdlib.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void func1() {
	printf("Function 1 call on exit\n");
}

void func2() {
	printf("Function 2 call on exit\n");
}

int main() {
	atexit(func1);
	atexit(func2);
	exit(0);
}

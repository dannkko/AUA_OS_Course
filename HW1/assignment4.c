#include "stdio.h"

int main() {
	int var = 4;
	int *ptr = &var;
	int **double_ptr = &ptr;

	printf("The value of 'var' using 'ptr': %d\nThe value of 'var' using 'double_ptr': %d\n", *ptr, **double_ptr);
}

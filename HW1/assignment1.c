#include "stdio.h"

int main() {
	int var = 20;
	int *ptr = &var;
	printf("Address using 'var':%p\nAddress using 'ptr':%p\n", &var, ptr);
	*ptr = 50;
	printf("New var value: %d\n", var);
}

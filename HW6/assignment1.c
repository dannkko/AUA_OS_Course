#include <stdio.h>

int main() {
	int var_int;
	char var_char;
	double var_double;
	short var_short;

	printf("var_int size: %ld\n", sizeof(var_int));
	printf("var_char size: %ld\n", sizeof(var_char));
	printf("var_double size: %ld\n", sizeof(var_double));
	printf("var_short size: %ld\n", sizeof(var_short));
		
	printf("var_int address: %p\n", &var_int);
	printf("var_char address: %p\n", &var_char);
	printf("var_double address: %p\n", &var_double);
	printf("var_short address: %p\n", &var_short);
	return 0;
}

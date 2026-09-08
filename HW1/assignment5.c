#include "stdio.h"

int main() {
	char str[] = "Hello";
	char *ptr = str;
	int char_num = 0;
	while (*ptr) {
		char_num++;
		printf("%c", *ptr++);
	}
	printf("\nString length: %d\n", char_num);
}

#include <stdio.h>

int main() {
	struct Types {
		char a;
		double b;
		int c;
	};
	struct Types my_struct;
	printf("The size of my_struct: %ld\n", sizeof(my_struct));
	printf("Field a address: %p\n", &my_struct.a);
	printf("Field b address: %p\n", &my_struct.b);
	printf("Field c address: %p\n", &my_struct.c);
	return 0;
}

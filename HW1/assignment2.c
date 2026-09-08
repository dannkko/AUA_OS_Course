#include "stdio.h"

#define ARR_SIZE 5

int main() {
	int arr[ARR_SIZE] = {1, 2, 3, 4, 5};
	int *ptr = arr;
	size_t i;

	printf("Array elements using 'ptr': ");
	for (i = 0; i < ARR_SIZE; i++)
		printf("%d, ", *ptr++);
	printf("\n");
	ptr = arr;

	for (i = 0; i < ARR_SIZE; i++)
		*ptr++ = i*2;
	ptr = arr;

	printf("Updated array elements using 'ptr': ");
	for (i = 0; i < ARR_SIZE; i++)
		printf("%d, ", *ptr++);
	printf("\n");
	printf("Updated array elements using 'array': ");
	for (i = 0; i < ARR_SIZE; i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 10, new_size = 5;
	int *arr = malloc(size * sizeof(int));
	if (!arr) {
		perror("malloc failed!");
		return -1;
	}

	printf("Enter %d integers: ", size);
	for (size_t i = 0; i < size; i++) {
		scanf("%d", arr + i);
	}

	int *short_arr = realloc(arr, new_size * sizeof(int));
	if (!short_arr) {
		perror("realloc failed!");
		free(arr);
		return -1;
	}

	printf("Array after resizing: ");
	for (size_t i = 0; i < new_size; i++) {
		printf("%d ", short_arr[i]);
	}
	printf("\n");

	free(short_arr);

	return 0;
}

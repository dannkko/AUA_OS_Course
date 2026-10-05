#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	if (n <= 0) {
		printf("The number of elements is not positive!");
		return -1;
	}

	int *arr = calloc(n, sizeof(int));
	if (!arr) {
		perror("calloc failed!");
		return -1;
	}

	printf("Array after calloc: ");
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Enter %d integers: ", n);
	for (size_t i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	float avg = 0;

	printf("Updated array: ");
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
		avg += arr[i];
	}
	printf("\n");

	avg /= n;
	printf("Average of the array: %.2f\n", avg);

	free(arr);

	return 0;
}

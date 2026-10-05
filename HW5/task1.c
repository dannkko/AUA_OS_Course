#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	printf("Enter the number of elements: ");
	scanf("%d", &n);	
	if (n < 0) {
		printf("Negative number of integers!\n");
		return -1;
	}
	
	if (n == 0) {
		printf("The sum of 0 elements is 0.\n");
		return 0;
	}

	int *arr = malloc(sizeof(int) * n);
	if (!arr) {
		perror("malloc failed!");
		return -1;
	}

	printf("Enter %d integers: ", n);
	for (size_t i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	int sum = 0;

	for (size_t i = 0; i < n; i++) {
		sum += arr[i];
	}
	printf("The sum of %d numbers: %d\n", n, sum);

	free(arr);

	return 0;
}

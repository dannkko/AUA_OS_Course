#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int stud_num;

	printf("Enter the number of students in class: ");
	scanf("%d", &stud_num);

	int *grade = malloc(stud_num * sizeof(int));
	if (!grade) {
		perror("malloc failed!");
		return -1;
	}

	printf("Enter the grades: ");
	for (size_t i = 0; i < stud_num; i++) {
		scanf("%d", grade + i);
	}

	int max = 0, min = INT_MAX;

	for (size_t i = 0; i < stud_num; i++) {
		if (grade[i] > max)
			max = grade[i];
		if (grade[i] < min)
			min = grade[i];
	}

	printf("Highest grade: %d\n", max);
	printf("Lowest grade: %d\n", min);

	free(grade);

	return 0;
}

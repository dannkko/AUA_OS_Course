#include <stdio.h>
#include <stdlib.h>

void free_string_array(char **arr, int string_num) {
	if (!arr)
		return;

	for (size_t i = 0; i < string_num; i++) {
		free(arr[i]);
	}
	free(arr);
}

int main() {
	int max_length = 50;
	int string_num = 3;

	char **str = malloc(string_num * sizeof(char*));
	if (!str) {
		perror("malloc failed!");
		return -1;
	}
	for (size_t i = 0; i < string_num; i++) {
		str[i] = malloc(max_length * sizeof(char));
		if (!str[i]) {
			perror("malloc failed!");
			free_string_array(str, i);
			return -1;
		}
	}

	printf("Enter 3 strings: ");
	for (size_t i = 0; i < string_num; i++) {
		scanf("%s", str[i]);
	}

	int new_string_num = 5;	// must be greater than or equal to string_num
	
	char **str_long = realloc(str, new_string_num * sizeof(char*));
	if (!str_long) {
		perror("realloc failed!");
		free_string_array(str, string_num);
		return -1;
	}
	for (size_t i = 0; i < new_string_num - string_num; i++) {
		str_long[string_num + i] = malloc(max_length * sizeof(char));
		if (!str_long[string_num + i]) {
			perror("malloc failed!");
			free_string_array(str_long, string_num + i);
			return -1;
		}
	}

	printf("Enter %d more strings: ", new_string_num - string_num);
	for (size_t i = 0; i < new_string_num - string_num; i++) {
		scanf("%s", str_long[string_num + i]);
	}
	printf("All strings: ");
	for (size_t i = 0; i < new_string_num; i++) {
		printf("%s ", str_long[i]);
	}
	printf("\n");

	free_string_array(str_long, new_string_num);

	return 0;
}

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() {
	printf("Before fork\n");	
	fork();
	printf("\tAfter the first fork\n");	
        fork();
	printf("\t\tAfter the second fork\n");	
        fork();
	printf("\t\t\tAfter the third fork\n");	
	return 0; 
} 

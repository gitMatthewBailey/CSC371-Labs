// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2023/24)
// 
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE 13

void generateTable(int num, int *table);
void printTable(int num, int *table);

int main(int argc , char *argv[]) {
	//Checking if the number of arguments is correct (only 1 expected input)
	if (argc != 2) {
		printf("%s <num>\n where <num> is an integer between 0 and 12\n", argv[0]);
		return -1;
	}

//Using atoi helps to prevent errors and ensure that the program receives a valid integer 
//input from the command line. Returns 0 if input cannot be converted.
	int num = atoi(argv[1]);
	if (num < 0 || num > 12) {
		printf("Invalid number size! Must be between 0 and 12.\n");
		return -1;
	}
	
	//malloc signature is void *malloc(size_t size); so we must cast to int *
	//malloc returns a pointer to the allocated memory.
	//sizeof(int) the function needs to know how big each block allocated is, and sizeof
	//makes this very clear to us that what we need is the size of an int.
	int *values = (int*) malloc(MAX_TABLE_SIZE * sizeof(int));
	//int values[MAX_TABLE_SIZE];
	if (values == NULL) {
		printf("Memory allocation failed.\n");
		return -1;
	}
	generateTable(num, values);
	printTable(num, values);
	
	free(values);

	return 0;
}

void generateTable(int num, int *table) {
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		table[i] = i * num;
	}
}

void printTable(int num, int *table) {
	printf("%-2d times table\n--------------\n", num);
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		printf("%-2d * %-2d = %d\n", num, i, *(table+i));
	}
	printf("\n");
}

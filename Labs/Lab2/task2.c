// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2023/24)
// 
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"



//TODO: Move function prototypes into their own header guard file
//DONE.


int main(int argc , char *argv[]) {
	//Checking if the number of arguments is correct (only 1 expected input)
	/* if (argc != 2) {
		printf("%s <num>\n where <num> is an integer between 0 and 12\n", argv[0]);
		return -1;
	} */

	int *tables[13]; // Array of pointers to int
    int i;
    for (i = 0; i < 13; i++) {
        tables[i] = (int*)malloc(MAX_TABLE_SIZE * sizeof(int));
        if (tables[i] == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        generateTable(i, tables[i]);
		//Used to debug:
		//printTable(i, tables[i]);
		//TODO: free memory associated with these tables
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

	//TODO: modify main function to call printTables
	printTables(tables); // Pass the tables array directly
    for (i = 0; i < 13; i++) {
        free(tables[i]); // Freeing memory for each table after printing
    }
	
	free(values);

	return 0;
}

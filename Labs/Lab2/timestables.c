#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"

/**
 * Generates a table of integers based on the given number.
 * @param num the number to generate the table from
 * @param table a pointer to an integer array that stores the generated table
 */
void generateTable(int num, int *table){
    int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		table[i] = i * num;
	}
}

/**
 * Prints a table of integers based on the given number.
 * @param num the number to generate the table from
 * @param table a pointer to an integer array that stores the generated table
 */
void printTable(int num, int *table){
    printf("%-2d times table\n--------------\n", num);
	int i;
	for (i = 0; i < MAX_TABLE_SIZE; i++) {
		printf("%-2d * %-2d = %d\n", num, i, *(table+i));
	}
	printf("\n");
}

//In this function, we take a double pointer as a parameter, as we can 
//use the fact it is pointing to the start of where the tables have been
//generated in memory, in order to iterate over where each table starts and print it.
void printTables(int **tables) {
    int i;
    for (i = 0; i <= MAX_TIMES_TABLE; i++) {
        printTable(i, tables[i]);
    }
}
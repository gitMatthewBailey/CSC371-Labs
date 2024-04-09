#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h library for atoi function
#include "fibonacci.h"

int main(int argc, char* argv[]) {
    //Expecting a single value passed by the cmd line so the number of args must equal 2 or more
    //for the program to work, so we check that here
    if (argc < 2) {
        printf("Please provide a number as a command line argument.\n");
        return -1; // Return an error code
    }
    int num = atoi(argv[1]); // Convert the command line argument to an integer
    
    int result = fibonacci(num);
    printf("Fibonacci of %d is %d\n", num, result);
    return 0;
}

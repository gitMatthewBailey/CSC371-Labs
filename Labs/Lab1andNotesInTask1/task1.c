//C and C++ compilation consists of a preprocessor that passes through the code
//first and makes a number of substitutions. The driectives start with #
#include <stdio.h> //This is a platform dependanct header to facilitate the use of stdin and stdout
//Can compile code in one go if had mulitple implementations: gcc task1.c task1-function.c -o task1
//or run in two stages: gcc -c task1.c -o task1.o and gcc -c task1-function.c -o task1-function.o
//and then you can link those object files to a single exe binary: gcc task1.o task1-function.o -o task1

//----------------------------------------------------------------------------------
//My first program and introduction in C
/* Will be adding comments to help learning */
//----------------------------------------------------------------------------------

    /* A declaration is something that tells the compiler the name and type of a property
    • e.g., a function prototype tells the compiler the name, parameters and return type
    A definition tells the compiler the name and type of a property, and allocates some memory somewhere for it
    Typically variable declarations are also definitions* because where we make a variable definitions will depend on where space is allocated in memory
    (* 
     = unless you use the extern keyword, e.g., extern int a;) */
//---------------------------------------------------------------------------------
//*** REVISION ***/**
//-----------------------------------------------------------------------------------
    /* * The stack is a region of memory that stores data and the memory addresses of the active subroutines in a program.
    * It is automatically managed by the compiler and the CPU.
    * The stack grows and shrinks as functions are called and return.
    * The stack is used for local variables, function parameters, and return addresses.
    * It is efficient for fast memory allocation and deallocation, but has a fixed size.
    * 
    * The heap, on the other hand, is a region of memory that is used for dynamic memory allocation.
    * It is managed by the programmer using functions like malloc, calloc, and realloc.
    * The heap is used for storing data structures, arrays, and objects that have a variable size or need to persist beyond the lifetime of a function.
    */
   //What happens when we run out of heap memory?
   //On a more older computer architecture you can get a blue screen because of corrupted code
   //Nowadays read/writes will be restricted, and you might just crash the program.

//----------------------------------------------------------------------------------
//Global variables can be created in the global scope, but you cannot execute 
//statements outside of functions
int globalVar;
/* globalVar = 7; would be invalid here */
int anotherGlobalVar = 42;
//----------------------------------------------------------------------------------


// main is the first thing ran inside the C program
//Takes two parameters, the number of arguments and the array of arguments
//The char* part means each element of the array is a pointer to a string of characters. 
//The array itself is not initialized and will contain garbage values until it is assigned memory and values.
int main(int argc, char* argv[])
{
    printf("Hello, World!\n");
    /* if you have a variable char myVar and want to print this, you could use:
    printf("Hello, %c!\n", myVar);
    %d is a signed Integer, %f is a float, %u is an unsigned integer, more on Google */
    //prints to stdout

//----------------------------------------------------------------------------------
    
    //C is pass by value - when you call a function, a copy of the variables is made.
    //Therefore if a change to the variable occurs it will only change that copy, not the original. 
    
    //But we can use pointers to pass a memory address to a function which enables them to modify the original variable, which
    //is not the same as pass by reference as it creates a copy of the pointer.

    /* void pass_by_pointer (int *arg) {
        *arg = 7;
    }

    int main() {
        int h2g2 = 42;
        int *p = &h2g2;

        printf("The answer is %d\n", h2g2); // 42
        pass_by_pointer (p); //Or alternatively don't need to create the pointer, can just pass the address
        //pass_by_pointer (&h2g2);
        printf("The answer is now %d\n", h2g2); // 7
    } */

//------------------------------------------------------------------------------------
    
    //Ifs and Loops
    //the way if conditionals work is if the condition is Integer 0 its false, anything else
    //is true.
    //for and while loops you have to declare the incrementing variable first before entering.
    //for (;;){} is an infinite loop. While(1){} is an endless loop.
    //do-while loops are similar to while loops but the condition is checked at the end of
    //the loop: int k = 0;do{k++} while(k<5); for example

//------------------------------------------------------------------------------------
    
    //C has a global scope and a local scope. Global vars are visible to all functions
    //Local vars are only visible to the function they are declared in.

    globalVar = 7;

    //only the changes to global vars persists after this local scope, no auto
    //garbage collection process so if handling sensitive data you might want to ZERO
    //OUT the local var at the end of the scope or make use of static keyword  within
    //the local scope as 'static' makes the variable persistent.
    static int staticLocalVar = 0;
    staticLocalVar += 1;
    printf("staticLocalVar = %d\n", staticLocalVar); //this will now increase and var will persist even if the scope ends.
    //static in the global scope is similar to private in C#, and normally is in other languages like Java
    //a var or func is for the private use of functions in the declaring file only (so 'static' affects visibility).

    //char (8-bit), short (16-bit), int (32-bit), long (64-bit).
    //unsigned char (8-bit), unsigned short (16-bit), unsigned int (32-bit), unsigned long (64-bit).
    //float (32-bit), double (64-bit).
    //performance of each type depends on the platform.
    //C standard specifies the min sizes and the relative ordering. Other types are built upon these basic types.
    //For example, 32-bit or 64-bit computer refers the size of the integer the hardware uses to address into memory.
    int localVar;
    localVar = 5;

//--------------------------------------------------------------------------------------------------------------------

    //Pointers are used to store addresses in memory. They also hold the type of data they point to.
    int h2g2 = 42;
    int *p = &h2g2;

    //Equivalent ways to access the same data
    printf("The value %d is at p\n", h2g2, &h2g2);
    // The value 42 is at 0x7ffeebd7d78c
    printf("The value %d is at %p\n", h2g2, p);
    // The value 42 is at 0x7ffeebd7d78c
    printf("The value %d is at %p\n", *p, p); //*p is the value stored at the address pointed to by p
    // The value 42 is at 0x7ffeebd7d78c

//--------------------------------------------------------------------------------------------------------------------
    
    //In C, there is no string type, instead we have contiguous blocks of chars in memory, terminated by a null character (\0)

    /* We refer to the string by the location of the first char in memory
     We can use either the array syntax or a shorthand syntax with double quotes: */
    char arr[] = {'H', 'e', 'l', 'l', 'o', ' ','W', 'o', 'r', 'l', 'd', '\0'};
    char *str = "Hello World";

    //We use %s format specifier in printf, and provide the address of the string:
    printf("str = %s", str);
    
    //The following code compiles:
    char c = 'H';
    printf("%s\n", &c);
    //printf() wants a char*, and &c is a char*
    //Not all char*s are strings! A char* could just be a pointer to a char
    // Note that C's string functions (e.g. strcpy) all expect a string
    //C is expecting you to do the right thing and not allow for stuff like esgmentation faults.

    localVar = 0;
    //zero out the local var so that the value isn't left over in memory.

    return 0;
    //0 tells the terminal that the program ran successfully
}
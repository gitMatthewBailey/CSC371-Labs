#include "fibonacci.h"

//This function takes a signed integer and returns a signed integer.
//When n is less than or equal to 0, return 0, when f equals 1 return 1, otherwise
//return a recursive call to fibonacci(n-1) + fibonacci(n-2).
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
#include "factorial.h"

int factorial(int number)
{   // negative numbers? large numbers? stack overflow?
    if (0 == number) return 1;
    return number <= 1 ? number : factorial(number-1)*number;
}
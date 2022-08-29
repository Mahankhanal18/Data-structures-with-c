// i. Develop a C program to illustrate recursion in finding factorial of a number
#include <stdio.h>

int fact(int userNumber)
{
    if (userNumber == 0)
        return (1);
    return (userNumber * fact(userNumber - 1));
}
int main()
{
    int factorialValue, userNumber;
    printf(" Enter the Number to Find Factorial :");
    scanf("%d", &userNumber);

    factorialValue = fact(userNumber);
    printf(" Factorial of %d is %d", userNumber, factorialValue);

    return 0;
}
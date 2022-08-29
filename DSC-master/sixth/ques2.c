
// ii. Develop a C program to illustrate recursion in printing Fibonacci series.
#include <stdio.h>
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{
    int i, userNumber;
    printf("\nEnter the number to find the fibonacci series\n");
    scanf("%d", &userNumber);
    for (i = 0; i < userNumber; i++)
    {
        printf(" %d ", fibonacci(i));
    }
}

// iii. Find GCD of two integers using recursion
#include <stdio.h>
int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;

    return gcd(num2, num1 % num2);
}

int main()
{
    int num1, num2;
    printf("\n Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    printf(" G.C.D is %d.", gcd(num1, num2));
    return 0;
}

#include <stdio.h>

#define max 100

int stack[max], top = -1, i, x;

void push(int x)
{
    ++top;
    stack[top] = x;
}
int pop()
{
    return stack[top];
}

void main()
{
    int num, total = 0, item;
    printf("Please enter a decimal: ");
    scanf("%d", &num);

    while (num > 0)
    {
        total = num % 2;
        push(total);
        num = num / 2;
    }

    for (i = top; top > -1; top--)
    {
        item = pop();
        printf("%d", item);
    }
}
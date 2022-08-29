#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stack;
int top = -1;
void push(char element)
{
    stack[++top] = element;
}
char pop()
{
    return stack[top--];
}
int isPalindrome(char userString[])
{
    int length = strlen(userString);
    stack = (char *)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length / 2; i++)
    {
        push(userString[i]);
    }

    if (length % 2 != 0)
    {
        i++;
    }
    while (userString[i] != '\0')
    {
        char element = pop();

        if (element != userString[i])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char userString[100];
    printf("\nEnter your string: ");
    scanf("%s", userString);

    if (isPalindrome(userString))
    {
        printf("Yes, the given string \'%s\' is palindrome ", userString);
    }
    else
    {
        printf("No, the given string \'%s\' is not palindrome ", userString);
    }
    return 0;
}
// Program to convert infix to postfix expression and its evaluation using stacks.
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char userExpression[100];
    char *evaluationExpression, x;
    printf("Enter the expression : ");
    scanf("%s", userExpression);
    printf("\n");
    evaluationExpression = userExpression;

    while (*evaluationExpression != '\0')
    {
        if (isalnum(*evaluationExpression))
            printf("%c ", *evaluationExpression);
        else if (*evaluationExpression == '(')
            push(*evaluationExpression);
        else if (*evaluationExpression == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*evaluationExpression))
                printf("%c ", pop());
            push(*evaluationExpression);
        }
        evaluationExpression++;
    }

    if (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}
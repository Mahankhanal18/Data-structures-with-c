// Program to implement Stack data structure using an array
#include <stdio.h>
#include <stdlib.h>
int stack[100], top = -1, numberOfStackElement;

int push()
{
    int pushData;
    if (top >= numberOfStackElement - 1)
        printf("\nStack Overflow\n");
    else
    {
        printf("Enter the value to be pushed in the stack: ");
        scanf("%d", &pushData);
        top++;
        stack[top] = pushData;
    }
}

int pop()
{
    if (top <= -1)
        printf("\nStack Underflow\n");
    else
    {
        printf("Popped Element is %d", stack[top]);
        top--;
    }
}

int display()
{
    if (top > 0)
    {
        printf("Stack Elements: \n");
        for (int i = top; i >= 0; i--)
            printf("%d  ", stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

int peep()
{
    int i;
    printf("Enter the position you want to peep:\n");
    scanf("%d", &i);
    if (top - i <= -1)
    {
        printf("\nThe Stack is Overflow...");
    }
    else
    {
        printf("The element in position %d is %d", i, stack[i]);
    }
}

int peek()
{
    if (top == -1)
        printf("Stack is empty");

    else
    {
        printf("The top element is %d", stack[top]);
    }
}

int main()
{
    int userChoice;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &numberOfStackElement);
    printf("\n1:PUSH\n2:POP\n3:PEEK\n4:DISPLAY\n5:PEEP\n6:EXIT");
    do
    {
        printf("\nEnter your choice: \n");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            peep();
            break;

        case 6:
            break;

        default:
            printf("Please enter a valid choice");
        }
    } while (userChoice != 6);
    return 0;
}
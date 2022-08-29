// Perform stack operations using arrays
// PUSH,POP,DISPLAY
// PEEK - RETURNS TOP ELEMENT OF THE STACK
#include <stdio.h>
int stack[100], choice, numberOfStackElements, top = -1, pushData, i;
void push(void);
void pop(void);
void display(void);
void peek(void);
void peep(void);
int main()
{
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &numberOfStackElements);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n--------------------------------");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.Peek\n 5.Peep\n 6.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            peep();
            break;
        }
        case 6:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4/5/6)");
        }
        }
    } while (choice != 6);
    return 0;
}

void push()
{
    if (top >= numberOfStackElements - 1)
    {
        printf("Stack Overflow\n\n");
    }
    else
    {
        printf("Enter the value to be pushed in the stack: ");
        scanf("%d", &pushData);
        top++;
        stack[top] = pushData;
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack is underflow ");
    }
    else
    {
        printf("The poped element is %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

void peek()
{
    if (top == -1)
        printf("stack is empty\n");
    else
        printf("Top value is %d \n", stack[top]);
}

void peep()
{
    int i;
    printf("\nEnter Position for search: ");
    scanf("%d", &i);
    if (top - i <= -1)
    {
        printf("\nThe Stack is Overflow...");
        return;
    }
    else
    {
        printf("\nThe Element is: %d", stack[i]);
    }
}
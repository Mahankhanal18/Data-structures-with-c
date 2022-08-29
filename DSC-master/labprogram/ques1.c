// Implement circular/linear queue using arrays
// Implement a queue using a two stacks

#include <stdio.h>
#define MAXSIZE 5

int cArray[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAXSIZE - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cArray[rear] = item;
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("\n\nElement deleted from queue is : %d\n\n", cArray[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAXSIZE - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    int frontPos = front, rearPos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (frontPos <= rearPos)
        while (frontPos <= rearPos)
        {
            printf("%d \n", cArray[frontPos]);
            frontPos++;
        }
    else
    {
        while (frontPos <= MAXSIZE - 1)
        {
            printf("%d ", cArray[frontPos]);
            frontPos++;
        }
        frontPos = 0;
        while (frontPos <= rearPos)
        {
            printf("%d ", cArray[frontPos]);
            frontPos++;
        }
    }
    printf("\n");
}
int main()
{
    int choice, item;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);

            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}
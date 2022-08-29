#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int i = 2, data;
    head = (struct node *)malloc(sizeof(struct node));
    if (newnode = NULL)
    {
        printf("Space is not allocated\n");
        exit(0);
    }
    else
    {
        printf("Space is allocated successfully,Enter -1 to stop\n");
        printf("Enter the data for node 1 : ");
        scanf("%d", &data);
        if (data == -1)
            return;
        head->data = data;
        head->next = NULL;
        temp = head;
        while (1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Space is not allocated\n");
                exit(0);
            }
            else
            {
                printf("Enter the data for %d node : ", i);
                scanf("%d", &data);
                if (data == -1)
                    break;
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
                i++;
            }
        }
    }
}

void display()
{
    struct node *temp;
    printf("\n");
    if (head == NULL)
    {
        printf("Space is empty\n");
    }
    else
    {
        temp = head;
        int i = 1;
        while (temp != NULL)
        {
            printf("The node %d contains the data %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
        printf("\n");
    }
}
void maxDelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\n Max node deleted ");
    }
}

int maxNode()
{
    struct node *current = head;
    int max;
    if (head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        max = head->data;
        while (current != NULL)
        {
            if (max < current->data)
            {
                max = current->data;
            }
            current = current->next;
        }
        printf("Maximum value node in the list: %d\n", max);
    }
    maxDelete();
    return max;
}
int main()
{
    int userChoice, insertingElement;
    create();
    display();
    while (1)
    {
        printf("\n1:Enter 1 to delete max node \n2: Enter 2 to display \n0: Enter 0 to Exit\n ");
        scanf("%d", &userChoice);
        if (userChoice == 1)
        {
            maxNode();
        }
        else if (userChoice == 2)
        {
            display();
        }
        else if (userChoice == 0)
        {
            exit(0);
        }
        else
        {
            printf("Enter insertingElement Valid Number\n");
        }
    }
}

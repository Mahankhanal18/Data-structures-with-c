// Develop a program to implement following operations on a doubly linked list: i) insert before a given value ii) Delete the middle Node
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head, *last;
void nodeInsertion();
int insertBefore();
void deleteSpecified();
void display();

void createList()
{
    int i = 2, data;
    struct node *newNode;

    head = (struct node *)malloc(sizeof(struct node));

    if (head != NULL)
    {
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        if (data == -1)
            return;

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        while (1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Space is not allocated\n");
                exit(0);
            }
            else
            {
                printf("Enter data of %d node: ", i);
                scanf("%d", &data);
                if (data == -1)
                    break;
                newNode->data = data;
                newNode->prev = last;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
                i++;
            }
        }
    }
}
void main()
{
    int choice = 0, data;
    printf("Enter -1 to stop adding data: ");
    createList();
    while (choice != 4)
    {
        printf("\n1: Insert Before Given Value\n2: Delete\n3: Display\n4: Exit");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertBefore();
            break;
        case 2:
            deleteSpecified();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
int insertBefore()
{

    struct node *newnode, *ptr, *preptr;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to insert-> ");
    scanf("%d", &newnode->data);
    printf("\nEnter the value Before which you want to insert node: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    if (ptr->data == val)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Value not found\n");
                return 1;
            }
        }
        preptr->next = newnode;
        newnode->next = ptr;
    }
}
void deleteSpecified()
{
    struct node *ptr, *temp;
    int val;
    printf("Enter the value after which you want to delete node: ");
    scanf("%d", &val);
    temp = head;
    while (temp->data != val)
    {
        temp = temp->next;
    }
    if (temp->next->next == NULL)
    {
        temp->next = NULL;
        printf("\nNode Deleted\n");
    }
    else
    {

        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void display()
{
    struct node *ptr;
    printf("\n printing values...\n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
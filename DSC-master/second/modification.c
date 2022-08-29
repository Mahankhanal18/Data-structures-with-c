//   Try to implement the following modifications in the code
// Use structures, functions and pointers
// 1. Menu driven, 1.Insert,2.Delete,3.Exit. After inserting and deleting an element call display function.
// 2. Insert an element in the particular position
// 3. Delete an element by giving its value.
// 4.Find the maximum value in the list
// 5.Find the minimum value in the list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head;

void menu();

void menu()
{
    int option;
    int c = 1;
    printf("\n1. Enter nodes.");
    printf("\n 2. Print nodes.");
    printf("\n 3. Enter node at desired position.");
    printf("\n 4. Delete nodes.");
    printf("\n 5. Print maximum and minimum value");
    printf("\n 6. Exit\n\n Enter your option ->");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        createNodes();
        break;
    case 2:
        printNodes();
        break;
    case 3:
        insertAny();
        break;
    case 4:
        printf("\n \n Do u want to delete first element ?[1/-1]: ");
        scanf("%d", &c);

        while ((c == 1) && (head != NULL))
        {
            del_nodes();
            printf("\n Do u want to delete more ?[1/-1] : ");
            scanf("%d", &c);
        }
        menu();
        break;
    case 5:
        print_extreme();
        break;
    case 6:
        return;
        break;
    default:
        printf("\n\n Enter correct choice !!!\n");
        menu();
    }
}

void createNodes()
{
    int d, i = 1;
    int c = 3;
    Node *newNode;

    while (c--)
    {
        newNode = (Node *)malloc(sizeof(Node));
        if (!newNode)
        {
            printf("\n Error in allocating memory!!!");
            exit(0);
        }
        newNode->link = NULL;
        printf("\n Enter the data for node %d : ", i++);
        scanf("%d", &d);
        newNode->data = d;
        newNode->link = head;
        head = newNode;
    }
    menu();
}

void printNodes()
{
    int i = 1;
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("\n Data %d", i++);
        printf(":  %d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
    menu();
}

void insertAny()
{
    bool flag = false;
    int d, n, i = 2;
    printf("\n Enter the node before which u want to enter the data-> ");
    scanf("%d", &n);
    Node *temp, *newNode;
    temp = head;
    while (temp != NULL)
    {
        if (temp->link->data == n)
        {
            flag = true;
            newNode = (Node *)malloc(sizeof(Node));
            if (!newNode)
            {
                printf("\n Error in allocating memory!!!");
                exit(0);
            }
            newNode->link = NULL;
            printf("\n Enter the data for node %d : ", i);
            scanf("%d", &d);
            newNode->data = d;
            newNode->link = temp->link;
            temp->link = newNode;
            break;
        }
        temp = temp->link;
        i++;
    }
    if (!flag)
    {
        printf("\n Please enter valid position!!!!");
    }
    menu();
}

void del_nodes()
{
    Node *temp;
    temp = head;
    printf("\n Deleted Element -> %d", temp->data);
    head = temp->link;
    free(temp);
}

void print_extreme()
{
    int max, min;
    max = head->data;
    min = head->data;
    Node *temp;
    temp = head->link;
    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        else if (temp->data < min)
            min = temp->data;

        temp = temp->link;
    }
    printf("\n Largest Node  -> %d", max);
    printf("\n Smallest Node -> %d", min);
}

int main()
{
    menu();

    while (head != NULL)
    {
        Node *temp;
        temp = head;
        head = temp->link;
        free(temp);
    }
    return 0;
}
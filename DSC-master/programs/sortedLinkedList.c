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

void sortingList()
{
    struct node *current = head, *index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int insertData(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;
}
int main()
{
    int insertedData;
    create();
    sortingList();
    display();
    printf("Enter the data to be inserted: \n");
    scanf("%d", &insertedData);
    insertData(insertedData);
    sortingList();
    display();
}
// Read two singly linked list and concatenate
// Sorting the concatenated data

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if (head != NULL)
    {
        printf("%d\t", head->data);
        display(head->next);
    }
}

void concatenate(struct node *node1, struct node *node2)
{
    if (node1 != NULL && node2 != NULL)
    {
        if (node1->next == NULL)
        {
            node1->next = node2;
        }
        else
        {
            concatenate(node1->next, node2);
        }
    }
    else
    {
        printf("Either of one node is NULL");
    }
}

int main()
{
    struct node *previous, *node1, *node2, *p;
    int n, i;
    printf("Number of Element in node 1: ");
    scanf("%d", &n);
    node1 = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (node1 == NULL)
        {
            node1 = p;
        }
        else
        {
            previous->next = p;
        }
        previous = p;
    }
    printf("Number of Element in node 2: ");
    scanf("%d", &n);
    node2 = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (node2 == NULL)
        {
            node2 = p;
        }
        else
        {
            previous->next = p;
        }
        previous = p;
    }
    concatenate(node1, node2);
    printf("Concatenated Data: \n");
    display(node1);
    return 0;
}
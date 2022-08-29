#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * first;
typedef struct node s;
void traverse(s *n);
void minimum();
void inputs(int n)
{
    s *temp, *new;
    int i;

    first = (struct node *)malloc(sizeof(struct node));

    printf("Enter 1st node \n");
    scanf("%d", &first->data);
    first->next = NULL;
    temp = first;
    for (i = 1; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter %d node \n", i + 1);
        scanf("%d", &new->data);
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
    }
}

int main()
{
    int n;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    inputs(n);
    traverse(first);
    Maximum();

    traverse(first);
    return 0;
}
void traverse(s *n)
{
    int i = 1;
    printf("Entered elements are\n");
    while (n != NULL)
    {
        printf("Node %d data : %d\n", i, n->data);
        n = n->next;
        i++;
    }
}
void Maximum()
{
    s *temp, *ptr;
    temp = first;
    int max = temp->data;
    while (temp != NULL)
    {
        if (max < temp->data)
            max = temp->data;
        temp = temp->next;
    }

    temp = first;
    ptr = temp->next;
    while (ptr->next != NULL)
    {
        if (max == temp->data)
            ptr->next = temp->next;
        ptr = ptr->next;
        temp = temp->next;
    }

    printf("\nMaximum value and deleted node  is : %d\n\n\n", max);
}
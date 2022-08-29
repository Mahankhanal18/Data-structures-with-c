#include<stdio.h>
#include<stdlib.h>
int n;
struct node
{
    int data;
    struct node *next,*prev;
};
struct node* get_node(int info)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=info;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
struct node* create_node(struct node *first)
{
    struct node *p,*g;
    int info;
    printf("Enter the number of nodes to be created\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the data : ");
        scanf("%d",&info);
        if(first==NULL)
        {
            p=get_node(info);
            first=p;
        }
        else
        {
            g=get_node(info);
            p->next=g;
            g->prev=p;
            p=p->next;
        }
        
    }
    return first;
}
void display(struct node *first)
{
    if(first==NULL)
        printf("\nList is empty");
    else
    {
        printf("List contains\n");
        while(first!=NULL)
        {
            printf("%d\t",first->data);
            first=first->next;
        }
    }
    
}

void rev_display(struct node *first)
{
    struct node *temp=first;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    printf("\nReversal of list\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
    return;
}

struct node* insert_before(struct node *first)
{
    struct node *temp=first,*p;
    int value,info;
    printf("Enter the value before which you want to insert\t");
    scanf("%d",&value);
    printf("Enter the new data");
    scanf("%d",&info);
    p=get_node(info);
    if(first->data==value)
    {
        n=n+1;
        p->next=first;
        first->prev=p;
        first=p;
        return first;
    }
    while(temp->data!=value && temp->next!=NULL)
    { 
        temp=temp->next;
    }
    if(temp->data!=value && temp->next==NULL)
    {
        printf("Invalid value");
        return first;
    }
    n=n+1;
    p->next=temp;
    p->prev=temp->prev;
    temp->prev=p;
    p->prev->next=p;
    return first;
}
struct node* delete_atmid(struct node *first)
{
    struct node *temp=first,*p;
    int m=1;
    if(first==NULL)
    {
        printf("\nList is empty");
        return first;
    }
    if(n==1)
    {
        printf("\nno middle element");
        free(first);
        return first;
    }
    if(n==2)
    {
        n=n-1;
        first=first->next;
        free(temp);
        return first;
    }
    if(n%2==0)
    {
        while(m!=(n/2))
        {
            m=m+1;
            p=temp;
            temp=temp->next;
        }
    }
    else
    {
        while((m)!=(n+1)/2)
        {
            m=m+1;
            p=temp;
            temp=temp->next;
        }
    }
    p->next=temp->next;
    p->next->prev=p;
    n=n-1;
    free(temp);
    return first;
}
int main()
{
    struct node *first=NULL;
    int op;
    first=create_node(first);
    do
    {
        printf("\nEnter: \n1 to insert before a given value\n2 to delete the middle node\n3 to display\n4 to display in reverse\n5 to exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                first=insert_before(first);
                break;
            case 2:
                first=delete_atmid(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                rev_display(first);
                break;
            default:
                break;
        }
    } while (op<5);
    return 0;
}

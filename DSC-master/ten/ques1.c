// Write a program to construct a Binary search tree and delete a given value
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *addNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}
void inOrderTraversal(struct node *rootnode)
{
    if (rootnode == NULL)
        return;
    if (rootnode->data != -1)
    {
        /* code */

        inOrderTraversal(rootnode->left);
        printf("%d -> ", rootnode->data);
        inOrderTraversal(rootnode->right);
    }
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return addNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    int userChoice, insNode, delNode;
    struct node *rootNode = NULL;
    printf("Enter -1 to stop\n");
    do
    {
        printf("Enter node to be inserted: ");
        scanf("%d", &insNode);
        rootNode = insert(rootNode, insNode);
    } while (insNode != -1);

    do
    {
        printf("\n\nEnter your choice\n1: Insert \n2: Display \n3: Delete \n4: Exit\n");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            printf("\nEnter node to be inserted: ");
            scanf("%d", &insNode);
            rootNode = insert(rootNode, insNode);
            break;
        case 2:
            printf("\nInorder Traversal is:\n");
            inOrderTraversal(rootNode);
            break;
        case 3:
            printf("Enter the node to delete: ");
            scanf("%d", &delNode);
            deleteNode(rootNode, delNode);
            inOrderTraversal(rootNode);
            break;
        case 4:
            break;
        default:
            printf("\nEnter valid choices\n");
            break;
        }
    } while (userChoice != 4);
    return 0;
}

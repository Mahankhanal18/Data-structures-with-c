// "Write a program to construct a Binary search tree and perform inorder, preorder, postorder traversals
// Count the number of parent nodes in the constructed BST
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
void preorderTraversal(struct node *rootnode)
{
    if (rootnode == NULL)
        return;
    printf("%d -> ", rootnode->data);
    preorderTraversal(rootnode->left);
    preorderTraversal(rootnode->right);
}

void postorderTraversal(struct node *rootnode)
{
    if (rootnode == NULL)
        return;
    postorderTraversal(rootnode->left);
    postorderTraversal(rootnode->right);
    printf("%d -> ", rootnode->data);
}
int count(struct node *tree)
{
    int c = 1;
    if (tree == NULL)
        return 0;
    else
    {
        if (tree->left != NULL || tree->right != NULL)
        {
            c += count(tree->left);
            c += count(tree->right);
            printf("%d -> ", tree->data);
            return c;
        }
    }
}
int main()
{
    int userChoice, insNode;
    struct node *rootNode = NULL;
    printf("Enter -1 to stop");
    do
    {
        printf("Enter node to be inserted: ");
        scanf("%d", &insNode);
        rootNode = insert(rootNode, insNode);
    } while (insNode != -1);

    do
    {
        printf("\n\nEnter your choice\n1:Insert Node\n2: Inorder Traversal\n3: PreOrderTraversal\n4: Postorder Traversal\n5:Print Number of parent Nodes \n6:Exit \n");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            printf("Enter node to be inserted: ");
            scanf("%d", &insNode);
            rootNode = insert(rootNode, insNode);
        case 2:
            printf("\nInorder Traversal is:\n");
            inOrderTraversal(rootNode);
            break;
        case 3:
            printf("\nPreorder Traversal is:\n");
            preorderTraversal(rootNode);
            break;
        case 4:
            printf("\nPostorder Traversal is:\n");
            postorderTraversal(rootNode);
            break;
        case 5:
            printf("The total number of parent nodes is: %d", count(rootNode));
            break;
        case 6:
            break;
        default:
            printf("\nEnter valid choices\n");
            break;
        }
    } while (userChoice != 6);
    return 0;
}

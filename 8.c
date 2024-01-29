// (a) Write a C program to construct a binary search tree of integers and also display the elements in the tree using Inorder, Preorder and Postorder traversals.
// (b) Write a C program to find the number of leaf nodes in a BST.
// (c) Write a C program to print all root to leaf paths of a BST.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node *root, struct node *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            insert(root->left, new_node);
        }
    }
    else if (new_node->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            insert(root->right, new_node);
        }
    }
    else
    {
        printf("Data already exists in BST");
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ", root->data);
}

int countLeafNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

void printPath(struct node *root, int path[], int pathlen)
{
    if (root == NULL)
    {
        return;
    }

    path[pathlen] = root->data;
    pathlen++;

    if (root->left == NULL && root->right == NULL)
    {
        printf("Path: ");
        for (int i = 0; i < pathlen; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    else
    {
        printPath(root->left, path, pathlen);
        printPath(root->right, path, pathlen);
    }
}

int main()
{
    struct node *root = NULL;
    struct node *new_node = NULL;
    struct node *result;
    int ch, data;
    while (1)
    {
        printf("\n-----------------MENU--------------------");
        printf("\n 1 - Insert node in BST");
        printf("\n 2 - Display BST in Preorder");
        printf("\n 3 - Display BST in Postorder");
        printf("\n 4 - Display BST in Inorder");
        printf("\n 5 - Count Number of Leaf Nodes");
        printf("\n 6 - Print all Root to Leaf Paths");
        printf("\n 7 - Exit\n");
        printf("------------------------------------------\n");
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            new_node = create();
            printf("\n Enter data: ");
            scanf("%d", &new_node->data);
            if (root == NULL)
            {
                root = new_node;
            }
            else
            {
                insert(root, new_node);
            }
            break;
        case 2:
            printf("\n BST in Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("\n BST in Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("\n BST in Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
            break;
        case 6:
            int path[100];
            printf("All Root to Leaf Paths: \n");
            printPath(root, path, 0);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("wrong choice\n");
        }
    }
}
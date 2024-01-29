// BST with Inorder, Postorder, Preorder traversal
// Insertion, Deletion, Search
// Find number of leaf node, internal node, total node, smallest node, largest node
// All root to leaf path

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

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
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

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
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

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    else
    {
        if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
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

int countInternalNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        return countInternalNodes(root->left) + countInternalNodes(root->right) + 1;
    }
}

int countTotalNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return countTotalNodes(root->left) + countTotalNodes(root->right) + 1;
    }
}

struct node *smallestNode(struct node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *largestNode(struct node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
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
        printf("\n 2 - Delete node in BST");
        printf("\n 3 - Display BST in Preorder");
        printf("\n 4 - Display BST in Postorder");
        printf("\n 5 - Display BST in Inorder");
        printf("\n 6 - Search for node");
        printf("\n 7 - Count Number of Leaf Nodes");
        printf("\n 8 - Count Internal Nodes");
        printf("\n 9 - Count Total Number of Nodes");
        printf("\n 10 - Find Smallest Node");
        printf("\n 11 - Find Largest Node");
        printf("\n 12 - Print all Root to Leaf Paths");
        printf("\n 13 - Exit\n");
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
            printf("\n Enter value to delete: ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("Node with value %d deleted from the BST\n", data);
            break;
        case 3:
            printf("\n BST in Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("\n BST in Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("\n BST in Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &data);
            result = search(root, data);
            if (result != NULL)
            {
                printf("Node with value %d found in the BST\n", data);
            }
            else
            {
                printf("Node with value %d not found in the BST\n", data);
            }
            break;
        case 7:
            printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
            break;
        case 8:
            printf("Number of Internal Nodes: %d\n", countInternalNodes(root));
            break;
        case 9:
            printf("Number of Total Nodes: %d\n", countTotalNodes(root));
            break;
        case 10:
            result = smallestNode(root);
            printf("Smallest Node in BST: %d\n", result->data);
            break;
        case 11:
            result = largestNode(root);
            printf("Largest Node in BST: %d\n", result->data);
            break;
        case 12:
            int path[100];
            printf("All Root to Leaf Paths: \n");
            printPath(root, path, 0);
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("wrong choice\n");
        }
    }
}
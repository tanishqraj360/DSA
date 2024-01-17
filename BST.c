#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
} *temp, *ptr, *root = NULL, *first = NULL;

void create(int data)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

void insert()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if (first == NULL)
    {
        create(data);
        first = temp;
        root = temp;
    }
    else if (data < root->data)
    {
        while (data < root->data && root->left != NULL)
        {
            
        }
    }
}
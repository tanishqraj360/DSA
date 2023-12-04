#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

int main()
{
    struct node *new_node, *ptr;
    int num;
    printf("\n enter the data");
    scanf("%d", &num);

    // creating a node.
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (start == NULL)
    {
        new_node->next = NULL;
        start = new_node;
    }
    printf("\n stored data=%d", start->data);

    return 0;
}
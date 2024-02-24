#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int count = 0;

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create(int data)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(NODE **top, int data)
{
    NODE *new_node = create(data);
    new_node->next = *top;
    *top = new_node;
    count++;
}

bool isEmpty(NODE *top)
{
    return top == NULL;
}

int pop(NODE **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    NODE *temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

void display(NODE *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return;
    }
    while (top != NULL)
    {
        printf("%d\t", top->data);
        top = top->next;
    }
    printf("\n");
}

int main()
{
    NODE *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);

    display(top);
}
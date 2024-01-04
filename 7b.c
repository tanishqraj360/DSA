// Write a C program to implement a circular queue using linked lists

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int count = 1;

struct node
{
    int data;
    struct node *next;
} *first = NULL, *temp, *ptr = NULL;

void insert()
{
    if (count > MAX)
    {
        printf("\nQueue Overflow\n");
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = temp;
    count++;

    ptr = first;
    if (ptr == NULL)
    {
        first = temp;
    }
    else
    {
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = first;
    }
}

void delete()
{
    ptr = first;
    temp = first;
    if (ptr == NULL)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }
        printf("Data to be deleted is %d", temp->data);
        if (ptr == temp)
        {
            free(temp);
            first = NULL;
        }
        else
        {
            ptr->next = temp->next;
            first = ptr->next;
            free(temp);
        }
        count--;
    }
}

void display()
{
    ptr = first;
    if (ptr == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements of queue\n");
        while (ptr->next != first)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n ", ptr->data);
    }
}

int main()
{
    while (1)
    {
        printf("\n----------MENU----------\n");
        printf("\n1.Insert\n2.Delete\n3. Display\n4. Exit\n");
        int ch;
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
}
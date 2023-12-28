/*Write a C program to support the following operations on a doubly linked list where each
    node consists of integers.
    (i) Create a doubly linked list by adding each node at the front.
    (ii)Insert a new node to the left of the node whose key value is read as an input.
    (iii) Delete the node of a given data, if it is found, otherwise display appropriate message.
    (iv) Display the contents of the list.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    struct node *prev;
    int data;
} *head = NULL, *temp = NULL, *tail = NULL, *ptr, *ptr1;

int count = 0;

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    count++;
}

void insert_at_first()
{
    if (head == NULL)
    {
        create();
        head = temp;
        tail = head;
    }
    else
    {
        create();
        temp->next = head;
        temp->prev = tail;
        head = temp;
    }
}

void insert_at_key()
{
    ptr = head;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        int key, flag = 0;
        printf("Enter key value: ");
        scanf("%d", &key);
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                flag = 1;
                break;
            }
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            if (ptr1 == NULL)
            {
                create();
                temp->next = head;
                temp->prev = tail;
                head = temp;
            }
            else
            {
                create();
                temp->next = ptr;
                ptr->prev = temp;
                ptr1->next = temp;
                temp->prev = ptr1;
            }
        }
        else
        {
            printf("\nKey value does not exist in list\n");
        }
    }
}

void delete_at_key()
{
    ptr = head;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        int key, flag = 0;
        printf("Enter key value: ");
        scanf("%d", &key);
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                flag = 1;
                break;
            }
            ptr1 = ptr;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            if (ptr1 == NULL)
            {
                printf("Data to be deleted: %d", ptr->data);
                head = ptr->next;
                ptr->next->prev = NULL;
                free(ptr);
            }
            else if (ptr->next == NULL)
            {
                printf("Data to be deleted: %d", ptr->data);
                ptr = tail;
                tail = ptr1;
                tail->next = NULL;
                free(ptr);
            }
            else
            {
                printf("Data to be deleted: %d", ptr->data);
                ptr->next->prev = ptr1;
                ptr1->next = ptr->next;
                free(ptr);
            }
            count--;
        }
        else
        {
            printf("\nKey value does not exist in list\n");
        }
    }
}

void display()
{
    ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\n Linked list elements: \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf(" No of nodes = %d", count);
}

int main()
{
    int ch, n, i;
    printf("-----------------MENU--------------------\n");
    printf("\n 1 - Create DLL with N nodes");
    printf("\n 2 - Display DLL");
    printf("\n 3 - Delete at Key value");
    printf("\n 4 - Insert at Key value");
    printf("\n 5 - Exit\n");
    printf("------------------------------------------\n");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter no of nodes: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insert_at_first();
            break;
        case 2:
            display();
            break;
        case 3:
            delete_at_key();
            break;
        case 4:
            insert_at_key();
            break;
        case 5:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}
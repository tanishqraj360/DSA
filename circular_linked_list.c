#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *temp, *ptr = NULL;

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = temp;
}

void insert_at_first()
{
    ptr = first;
    if (ptr == NULL)
    {
        create();
        first = temp;
    }
    else
    {
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }
        create();
        temp->next = first;
        ptr->next = temp;
        first = temp;
    }
}

void delete_at_front()
{
    ptr = first;
    temp = first;

    if (ptr == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }

        printf("Data to be deleted is %d\n", temp->data);

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
    }
}

void display()
{
    ptr = first;
    if (ptr == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        int count = 1;
        while (ptr->next != first)
        {
            printf("Data at node %d is %d\n", count, ptr->data);
            ptr = ptr->next;
            count++;
        }
        printf("Data at node %d is %d\n", count, ptr->data);
    }
}

int main()
{
    while (1)
    {
        printf("\n----MENU----\n");
        printf("1.Insert at front\n2.Delete at front\n3. Display\n4. Exit\n");
        int ch;
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_first();
            break;
        case 2:
            delete_at_front();
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
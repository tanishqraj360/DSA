#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL, *temp = NULL, *temp1, *ptr;

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    count++;
}

void display()
{
    temp1 = first;
    if (temp1 == NULL)
    {
        printf("List empty to display\n");
        return;
    }
    else
    {
        int cnt = 0;
        printf("\nLinked list elements from the beginning: \n");
        while (temp1 != NULL)
        {
            printf("Value at node %d is %d\n", cnt, temp1->data);
            temp1 = temp1->next;
            cnt++;
        }
        printf("Number of node = %d", count);
    }
}

void insert_at_first()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        temp->next = first;
        first = temp;
    }
}

void insert_at_position()
{
    int pos, count1 = 0, num;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Index out of range");
    }
    else
    {
        ptr = first;
        while (pos != count1)
        {
            temp1 = ptr;
            ptr = ptr->next;
            count1++;
        }
        create();
        temp1->next = temp;
        temp->next = ptr;
    }
}

int delete_at_value()
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (first == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        ptr = first;
        while (ptr->data != val)
        {
            temp1 = ptr;
            ptr = ptr->next;
        }
        printf("Data to be deleted %d", ptr->data);
        temp1->next = ptr->next;
        free(ptr);
        count--;
    }
}

int search_at_val()
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (first == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        int cnt = 0;
        ptr = first;
        while (ptr->data != val)
        {
            ptr = ptr->next;
            cnt++;
        }
        printf("Data %d is at node %d", ptr->data, cnt);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nLinked list\n");
        printf("1. Insert at front of the list\n2. Insert at any position in the list\n3. Deleting the node based on specific value\n4. Searching a node based on specific value\n5. Displaying all nodes in the list\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_first();
            break;
        case 2:
            insert_at_position();
            break;
        case 3:
            delete_at_value();
            break;
        case 4:
            search_at_val();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
            break;
        default:
            break;
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node
{
    struct node *next;
    int data;
}*prev=NULL,*first=NULL,*temp=NULL,*temp1,*next,*current;

void reverse() /*Main function*/
{
    current=first;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    first=prev;
}

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
        int cnt = 1;
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
    }
    else
    {
        create();
        temp->next = first;
        first = temp;
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nLinked list\n");
        printf("1. Insert at front of the list\n2. Reverse the list\n3. Displaying all nodes in the list\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_first();
            break;
        case 2:
            reverse();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            break;
        }
    }
}
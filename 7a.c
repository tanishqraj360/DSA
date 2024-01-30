// Write a C program to simulate the working of a queues 
// using an array provide and implement the following operations: 
// (i) Insert (ii) Delete (iii) Display Assume that the size of the queue is 5.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert()
{
    int item;
    if (rear == SIZE - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

void delete()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Underflow");
    }
    else
    {
        val = queue[front];
        printf("Deleted data: %d", val);
        ++front;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Elements of Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("\n-----------MENU----------\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        int ch, n;
        printf("Enter choice: ");
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
        default:
            printf("Invalid Input");
            break;
        }
    }
}

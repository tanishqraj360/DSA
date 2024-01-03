#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % MAX == front)
    {
        printf("Overflow");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Underflow");
    }
    else if (front == rear)
    {
        printf("Deleted data: %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted data: %d", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (i != rear)
    {
        printf("%d\t", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d", queue[i]);
    printf("\n");
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
            enqueue();
            break;
        case 2:
            dequeue();
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
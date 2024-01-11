#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int priority_queue[SIZE][SIZE];
int front[SIZE];
int rear[SIZE];
int flag = 0;
int priority;

void insert()
{
    int priority_i;
    int process_id;
    printf("Enter priority of process: ");
    scanf("%d", &priority_i);
    if (priority_i >= SIZE)
    {
        printf("Entered Priority is Invalid");
        return;
    }
    printf("Enter process id(int): ");
    scanf("%d", &process_id);

        if (front[priority_i] == -1 && rear[priority_i] == -1)
    {
        front[priority_i] = 0;
        rear[priority_i] = 0;
        priority_queue[priority_i][rear[priority_i]] = process_id;
    }
    else if ((rear[priority_i] + 1) % SIZE == front[priority_i])
    {
        printf("Overflow\n");
    }
    else
    {
        rear[priority_i] = (rear[priority_i] + 1) % SIZE;
        priority_queue[priority_i][rear[priority_i]] = process_id;
    }
}

void delete(int flag, int priority)
{
    if (flag == 0)
    {
        printf("Underflow\n");
    }
    else if (front[priority] == rear[priority])
    {
        printf("Terminated Process is %d of Priority %d\n", priority_queue[priority][front[priority]], priority);
        priority_queue[priority][front[priority]] = 0;
        front[priority] = -1;
        rear[priority] = -1;
    }
    else
    {
        printf("Terminated Process is %d of Priority %d\n", priority_queue[priority][front[priority]], priority);
        priority_queue[priority][front[priority]] = 0;
        front[priority] = (front[priority] + 1) % SIZE;
    }
}

void display(int flag)
{
    if (flag == 0)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("\n----------Priority Queue----------\n\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("Priority %d: ", i);
            for (int j = 0; j < SIZE; j++)
            {
                printf("%-10d", priority_queue[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int flag = 0, priority = 0;

    for (int i = 0; i < SIZE; i++)
    {
        front[i] = -1;
        rear[i] = -1;
    }

    while (1)
    {
        flag = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (front[i] != -1 && rear[i] != -1)
            {
                flag = 1;
                priority = i;
                break;
            }
        }
        printf("\n-----------PRIORITY QUEUE----------\n");
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
            delete (flag, priority);
            break;
        case 3:
            display(flag);
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Input");
            break;
        }
    }
}
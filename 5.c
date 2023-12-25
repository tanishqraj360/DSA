#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr[MAX];
int count = -1;

void push()
{
    if (count == MAX)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        count++;
        printf("Enter data to push: ");
        scanf("%d", &arr[count]);
    }
}

void pop()
{
    if (count == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int p;
        p = arr[count];
        arr[count] == NULL;
        count--;
        printf("Data Removed: %d\n", p);
    }
}

void display()
{
    if (count == -1)
    {
        printf("Stack Underflow\n");
    }
    else if (count == MAX + 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        for (int i = 0; i <= count; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        printf("\n-------MENU------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        int ch;
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Input");
        }
    }
    return 0;
}
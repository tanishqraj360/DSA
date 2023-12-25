#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr[MAX];
int top = -1;

void push()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        printf("Enter data to push: ");
        scanf("%d", &arr[top]);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Data Removed: %d\n", arr[top]);
        arr[top] = NULL;
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
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
/*Write a program to design, Develop and Implement a menu- driven program in C for the
    following operations on STACK of integers (Array implementation of the stack with
    maximum size MAX = 4).
    (i) Push an element on to stack.
    (ii) Pop an element from the stack.
    (iii) Check Overflow and Underflow situations on the stack.
    (iv) Display the contents of stack.
    (v) Exit.
    Support the program with appropriate functions for each of the above operations.*/

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
        return;
    }
    else
    {
        printf("Data Removed: %d\n", arr[top]);
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
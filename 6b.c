// Check whether a given string is a palindrome or not by using a stack.

#include <stdio.h>
#include <string.h>
#define SIZE 50

char string[SIZE];
char reversed_string[SIZE];
char stack[SIZE];
int top = -1;

void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}

int main()
{
    printf("Enter String: ");
    scanf("%s", string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        push(string[i]);
    }

    int length = top;

    for (int i = 0; i <= length; i++)
    {
        reversed_string[i] = pop();
    }

    if (strcmp(string, reversed_string) == 0)
    {
        printf("String is palindrome\n");
    }
    else
    {
        printf("String is not palindrome\n");
    }

    return 0;
}
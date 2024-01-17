// Check whether a given string is a palindrome or not by using a stack. (Without using string.h)

#include <stdio.h>
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
    printf("Enter string: ");
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

    int flag = 0;

    for (int i = 0; i <= length; i++)
    {
        if (string[i] == reversed_string[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }

    if (flag == 1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a Palindrome\n");
    }

    return 0;
}
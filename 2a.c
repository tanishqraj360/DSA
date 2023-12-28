/*Write a C program to read and display the Time in specified format. Create a
    structure called TIME with hour (int), minute(int), second(int) and next(self-
    referencing pointer ) as its members. Dynamically create two variables of structure
    TIME and link the first variable to the second one and display it. Write a Display
    function that takes address of first TIME variable and displays both times in the
    format h:m:s*/

#include <stdio.h>
#include <stdlib.h>

struct TIME
{
    int hour, minute, second;
    struct TIME *next;
};

void Display(struct TIME *t)
{
    printf("%d:%d:%d - %d:%d:%d\n", t->hour, t->minute, t->second, t->next->hour, t->next->minute, t->next->second);
}

int main()
{
    struct TIME *t1 = (struct TIME *)malloc(sizeof(struct TIME));
    struct TIME *t2 = (struct TIME *)malloc(sizeof(struct TIME));

    t1->hour = 10;
    t1->minute = 20;
    t1->second = 30;

    t2->hour = 20;
    t2->minute = 30;
    t2->second = 40;

    t1->next = t2;

    Display(t1);

    return 0;
}

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

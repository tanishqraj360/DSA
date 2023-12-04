#include <stdio.h>

int findMax(int *ptr1, int *ptr2, int *ptr3)
{
    if ((*ptr1 > *ptr2) && (*ptr1 > *ptr3))
    {
        return *ptr1;
    }
    else if ((*ptr2 > *ptr1) && (*ptr2 > *ptr3))
    {
        return *ptr2;
    }
    else
    {
        return *ptr3;
    }
}

int main()
{
    int num1, num2, num3, max;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    max = findMax(&num1, &num2, &num3);
    printf("Max number is: %d\n", max);
    return 0;
}
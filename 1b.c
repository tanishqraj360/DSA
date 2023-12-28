/*Write a C program using pointer for searching the desired element from the array
    using pointers*/

#include <stdio.h>

int main()
{
    int n, arr[20], key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search for: ");
    scanf("%d", &key);
    int *ptr = arr;

    for (int i = 0; i < n; i++)
    {
        if (*ptr == key)
        {
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
        ptr++;
    }

    if (!found)
    {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
#include <stdio.h>

int findMax(int *arr)
{
    int max;

    printf("%d\n", arr);
    for (int i = 0; i < 3; i++)
    {
        max = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("%d\n", (arr + i * 3 + j));
            if (max < *(arr + i * 3 + j))
            {
                max = *(arr + i * 3 + j);
            }
        }
        printf("Max element in row %d is %d\n", i + 1, max);
    }
}

int main()
{
    int arr[3][3], max = 0;
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findMax(&arr[0][0]);
    return 0;
}
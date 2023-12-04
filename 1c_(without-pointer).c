#include <stdio.h>

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

    for (int i = 0; i < 3; i++)
    {
        max = arr[i][0];
        for (int j = 1; j < 3; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
        printf("Max elemnt in row %d is %d\n", i + 1, max);
    }
    return 0;
}
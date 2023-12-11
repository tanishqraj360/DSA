#include <stdio.h>

int findMax(int *arr,int m,int n)
{
    int max;
    for (int i = 0; i < m; i++)
    {
        max = 0;
        for (int j = 0; j < n; j++)
        {
            if (max < *(arr + i * n + j))
            {
                max = *(arr + i * n + j);
            }
        }
        printf("Max element in row %d is %d\n", i + 1, max);
    }
}

int main()
{
    int arr[3][3], max = 0,row,col;
    printf("Enter number of row of the matrix: ");
    scanf("%d",&row);
    printf("Enter number of columns of the matrix: ");
    scanf("%d",&col);
    printf("Enter elements of the above matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    findMax(&arr[0][0],row,col);
    return 0;
}

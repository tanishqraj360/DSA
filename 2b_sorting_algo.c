#include <stdio.h>
int main()
{
    int n = 5;
    int s1[5] = {222,236, 243, 280, 295};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (s1[j] < s1[j + 1])
            {
                int temp = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = temp;
            }
            for (int k = 0; k < n; k++)
            {
                printf("%d ", s1[k]);
            }
            printf("\n");
        }
        printf("End\n");
    }
}

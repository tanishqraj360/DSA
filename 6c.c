#include <stdio.h>

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int main()
{
    int n, result;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Negative number entered");
    }
    else
    {
        result = fib(n);
    }

    printf("The %dth term in the Fibonacci series is: %d\n", n, result);

    return 0;
}
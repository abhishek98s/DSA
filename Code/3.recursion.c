#include <stdio.h>

int rec(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * rec(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number");
    scanf("%d", &n);

    printf("The factoria is %d", rec(n));
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf ("%d", &n);
    for (i = 1; i <= n; i ++){
        printf ("%d ", fib(i));
    }
    return 0;
}

fib(int i)
{
    int result;

    if (i == 1 || i == 2)
        result = 1;
    else
        result = fib(i-1) + (i-2);

    return result;

}


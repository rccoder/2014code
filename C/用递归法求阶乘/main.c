#include <stdio.h>
#include <stdlib.h>
double fact(int n);
main(void)
{
    int n;
    printf ("Give a number,I'll give you number!\nPlease input the number:\n");
    scanf ("%d", &n);
    printf ("%d! = %f", n, fact(n));
    return 0;
}

double fact(int n)
{

    double result;
    if (n == 1 || n == 0) result = 1;
    else result = n * fact(n - 1);
    return result;
}

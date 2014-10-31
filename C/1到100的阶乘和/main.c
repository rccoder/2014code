#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i,sum;
    sum = 0;
    for (i = 1; i <= 10; i++){
        sum = sum + fact(i);
    }
    printf ("1! + 2! + 3! + ¡­¡­ + 100! == %d\n", sum);
    return 0;
}


fact(i)
{
    int n;
    double result; /*int ÊÇÓÐ·¶Î§µÄ*/
    result = 1;
    for (n = 1; n <= i; n++){
        result = result * n;
        }
    return result;
}

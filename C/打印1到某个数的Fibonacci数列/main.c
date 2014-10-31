#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, a, b, flag;
    printf ("There is a calcultor for the calcul of the Fibonacci!\n\nPlease input the number, I can tell you the Fiboncci from 1 to this number!\n");
    scanf ("%d", &num);
    a = 1; b = 1;
    printf ("%6d %6d", a, b);
    while (b <= num){
        flag = a + b;
        if (flag > num) break;
        printf (" %6d", flag);
        a = b;
        b = flag;
    }

    return 0;
}

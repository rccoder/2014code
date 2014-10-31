#include <stdio.h>
#include <stdlib.h>
main(void)
{
    int i;
    double pi;
    pi = 0; i = 0;
    while ((1.0 / ((2 * i) + 1)) > pow(10, -4)){
        pi = pi + (pow((-1),(i))) * (1.0 / ((2 * i) + 1));
        i +=  1;
        }
    printf ("The value of the pi is: %.2f\n", pi * 4.0);
    return 0;
}


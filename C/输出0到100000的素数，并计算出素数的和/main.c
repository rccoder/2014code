#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
    int i, j, sum;
    sum = 0;
    for (i = 2; i < 100000; i ++){
        for (j = 2; j <= sqrt(i); j++){
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i)){
            sum += i;}
    }
    printf ("\n\nThe sum of the prime from 1 to 100000 is %d\n", sum);
    return 0;
}

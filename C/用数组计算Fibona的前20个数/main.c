#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int fibon[20] = {1, 1};
    for(i = 2; i <= 19; i++){
        fibon[i] = fibon[i - 1] + fibon[i - 2];
    }                                                   /*已经存进数据里面去了*/
    for(i = 0; i <= 19; i++){
        printf("%5d", fibon[i]);
        if ((i + 1) % 5 == 0)
            printf ("\n");
    }
    return 0;
}

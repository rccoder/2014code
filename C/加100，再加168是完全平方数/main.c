#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
    long int i, j, k;
    printf ("��Ҫ�ҵ���Ϊ��\n\n");
    for (i = 1; i <= 100000; i++){
        j = sqrt(i + 100);
        k = sqrt(i + 268);
        if (j * j == (i + 100) && k * k == (i + 268)){
            printf ("%d\n", i);}

    }
    if (i == 100000)
        printf ("Oh No!����û����Ҫ�ҵ���\n");
   return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][2];
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 2; j++)
        a[i][j] = i + j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
                printf("%4d", a[i][j]);

        }
        printf("\n");
        }

    return 0;
}

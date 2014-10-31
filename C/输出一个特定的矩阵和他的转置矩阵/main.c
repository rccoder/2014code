#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6][6];
    int i, j, n, tep;
    printf("Please input the number:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] = i * n + j + 1;
        }
    }
    printf("The original matrix is:\n\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%3d", a[i][j]);
        }
        printf("\n\n");
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i < j){
                tep = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = tep;
            }
        }
    }
    printf("The changed matrixi is:\n\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%3d", a[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}


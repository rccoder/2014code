#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, i, *p, sum;
    printf("Please input the n:\n");
    scanf("%d", &n);
    if ((p = (int *) malloc (n, sizeof(int))) == NULL){
        printf("Not able to allocate memory.\n");
        exit(1);
    }
    printf("Please input the %d integers:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", p+i);
    }
    sum = 0;
    for(i = 0; i < n; i++){
        sum += *(p+i);
    }
    printf("The sum is: %d", sum);
    free(p);
    return 0;
}

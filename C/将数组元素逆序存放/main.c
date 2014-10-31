#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[10], i, tep;
    printf("Please input the sum(<=10) of the number what you'll input next!\n");
    scanf("%d", &n);
    printf("Please input the number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i <= (n - 1) / 2; i++){
        tep = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tep;
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

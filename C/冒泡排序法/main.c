#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10], n, i, j, tep;
    printf("Please input the sum of the number what you'll sort!\n");
    scanf("%d", &n);
    printf ("Please input the num what you'll sort:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 1; i < n; i++){
        for (j = 0; j < n - i; j++){ /*后面的已经是大的*/
            if(a[j] > a[j + 1]){
                tep = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tep;
            }
        }
    }
    printf("The sorted group is:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

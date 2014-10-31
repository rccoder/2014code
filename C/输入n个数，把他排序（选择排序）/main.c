#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10], n, i, k,j, min_num, flag = 0, tep;
    printf("Please input the sum of the number what ypo'll input next£º\n");
    scanf("%d", &n);
    printf("Please input the %d number:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i ++){
        min_num = a[i];
        for(k = i + 1; k < n; k ++){
            if(a[k] <= min_num){
                flag = k;
                min_num = a[flag];
            }
        }
        if(flag > 0){
            tep = a[flag];
            a[flag] = a[i];/*找出最小值，再从数组中寻找这个值，记住下标；实验是不是最小值，如果是，则记住下标*/
            a[i] = tep;
            flag = 0;}

    }
    printf("The new order is :\n");
    for(i = 0; i < n; i++)
        printf ("%d ", a[i]);
    return 0;
}

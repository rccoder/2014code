#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, min_num, flag, tep;
    int a[10];
    printf ("Please input the sum of the number what you'll input next:\n");
    scanf ("%d", &n);
    printf ("Please input thqe %d number:\n", n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    min_num = a[0];
    for(i = 1; i < n; i ++){
        if (a[i] < min_num) min_num = a[i];
    }
    printf ("The min is :%d\n", min_num);
    for(i = 0; i < n; i++){
        if(a[i] == min_num){
            flag = i;
            printf ("The index of the min is:%d\n", i);
            break;}
    }
    tep = a[0];
    a[0] = a[flag];
    a[flag]= tep;
    printf ("The changed num qroup is:");
    for(i = 0; i < n; i++)
        printf ("%d ", a[i]);


    return 0;
}

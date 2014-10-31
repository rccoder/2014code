#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, flag;
    int num[5];
    printf ("Please input the original number!\n");
    for(i = 0; i <= 4; i ++){
        scanf("%d", &n);                              /*In this part,you also can write:scanf("%d", &num[i]*/
        num[i] = n;
    }
    printf ("Please input the num what you'll look up!\n");
    scanf("%d", &n);
    flag = 0;
    for(i = 0; i <= 4; i ++){
        if (num[i] == n){
            printf ("The index of the number what you finded is %d\n", i);
            flag = 1;
            break;}
    }
    if (flag == 0) printf ("No found!\n");



    return 0;
}

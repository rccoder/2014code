#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, digit;
    printf ("Please input a int:\n\n");
    scanf ("%d", & num);
    printf ("\n\nThe opposite number is：\n\n");
    do{
        digit = num % 10;
        num = num / 10;
        printf ("%d", digit);
    }while (num != 0);
    printf ("\n\n");
    return 0;/*几个单独的数字放在一起不就是一个数字了吗？*/
}

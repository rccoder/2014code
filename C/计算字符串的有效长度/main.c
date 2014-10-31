#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[6] = "happy";
    int i, flag = 0;
    for(i = 0; str[i] != '\0'; i++){
        flag ++;
    }
    printf("%d\n", flag);
    for(i = 0; str[i] != '\0'; i++){
        putchar(str[i]);
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[10];
    int i, num;
    printf("Please input the char:\n");
    i = 0;
    while((str[i] = getchar()) != '\n'){  /*ע����str[i] = getchar() != '\n'������*/
        i++;
    }
    str[i] = '\0';
    num = 0;
    for(i = 0; str[i] != '\0'; i++){
        num = num * 10 +(str[i] - '0');
    }
    printf("%d", num);
    return 0;
}

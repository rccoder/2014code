#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[80];
    int i, coun;
    printf("Please input the char:\n");
    str[0] = getchar();
    i = 0;
    while(str[i] != '\n'){
        i ++;
        str[i] = getchar();
    }
    str[i] = '\0';
    coun = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] <= '9' && str[i] >= '0'){
            coun ++;
        }
    }
    printf("The sum of the number in this char is: %d", coun);
    return 0;
}

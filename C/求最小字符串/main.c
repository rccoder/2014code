#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char sx[80], smin[80];
    scanf("%s", sx);
    strcpy(smin, sx);
    for(i = 1; i < 5; i++){
        scanf("%s", sx);
        if(strcmp(sx, smin) < 0)
            strcpy(smin, sx);
    }
    printf("The min is:%s\n", smin);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char line[100];
    gets(line);
    printf("%s\n", line);
    encrypt(line);
    printf("%s\n", line);
    return 0;
}/*
void encrypt(char *s)
{
    for(; *s != 0; s++){
        if(*s == 'z')
            *s = 'a';
        else
            *s = *s + 1;
    }
}
*/
void encrypt(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] = 'z')
            s[i] = 'a';
        else
            s[i] = s[i] + 1;
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    scanf ("%c", &ch);/*ch = getchar()*/
    while (ch != '\n'){
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        else if (ch >= 'a' && ch <= 'z')
                ch = ch - 'a' + 'A';
        printf("%c", ch);/*putchar(ch)*/
        scanf ("%c", &ch);
    }


    return 0;
}

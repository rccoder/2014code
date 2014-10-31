#include <stdio.h>
#include <stdlib.h>

int main()
{/*sa, sp, 和字符串都是地址*/
    char sa[] = "array is a";
    char *sp = "point";strcpy(sa, "hello");sp = "hello";
    printf("%s\n", sa);
    printf("%s", sp);
    printf("%s", "array");
    return 0;
}
smain{
char *s, str[20];
s = str;/*先赋值，后引用    s, str是地址*/
scanf("%s", s); /*是地址，所以就没有必要&，用来取地址*/

char *s =   NULL
return = 0;
}

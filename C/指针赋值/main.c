#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 2, b = 4, c = 6, *p1, *p2;
    p1 = &a; p2 = &b;
    printf("a = %d, b = %d, c = %d, *p1 = %d, *p2 = %d\n", a, b, c, *p1, *p2);
    p2 = p1; p1 = &c;/*p2 ==> a*/
    printf("a = %d, b = %d, c = %d, *p1 = %d, *p2 = %d\n", a, b, c, *p1, *p2);
    return 0;
}

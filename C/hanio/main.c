#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf ("Input the number:\n");
    scanf ("%d", &n);
    printf ("The step of hanio is:\n");
    hanio (n, "a", "b", "c");
    return 0;
}

void hanio (int n, char a, char b, char c)
{
    if (n==1) printf ("%c --> %c\n", a, b);
    else {
        hanio (n-1, a, c, b);/*a to c*/
        printf ("%c --> %c\n", a, b);
        hanio (n-1, c, b, a);
    }

}

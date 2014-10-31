/*#include <stdio.h>
int main(void)
{
    void num_tower(int n);
    num_tower(8);
    return 0;

}
void num_tower(int n)
{
    int i, j;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n - i; j ++)
            printf (" ");
        for (j = 1; j <= i; j ++)
            printf (" %d", i);
        putchar('\n');

    }
}
*/
#include <stdio.h>
main(void)
{
    int i, j;
    for (i = 1; i <= 8; i ++){
        for (j = 1; j <= 8 - i; j ++)
            printf (" ");
        for (j = 1; j <= i; j ++)
            printf (" %d", i);
        putchar('\n');
    }
}

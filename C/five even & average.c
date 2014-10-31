#include <stdio.h>
 
int main()
{
    int a[30], b[6] = {0,0,0}, j, i;
    j = 0;
    for(i = 2; i <= 60; i += 2)
    {
        a[j] = i;
        j++;
    }
    j = 0;
    for(i = 0; i < 30; i++)
    {
        b[j] += a[i];
        if((i+1) % 5 == 0)
            j++;
    }
    for(i = 0; i < 6; i++)
    {
        printf("%6d", b[i] / 5 );
    }
}
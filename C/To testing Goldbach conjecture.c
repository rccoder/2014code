#include <stdio.h>
#include <math.h>
int prime(int n)
{
    int i;
    for(i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
 
    int n, i, j, flag = 0;
    printf("Input a number:\n");
    scanf("%d", &n);
    if(n % 2 != 0)
        printf("Input error!\n");
    else
    {
        for(i = 2; i < n; i++)
        {
            for(j = 2; j < n; j++)
            {
                if(prime(i) == 1 && prime(j) == 1 && i + j == n)
                {
                    printf("%d=%d+%d\n", n, i, j);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int a, b, c, d, e, i, j, k, l, m, x, count = 0,f = 0; /*f:分解的5个数可以表示出1~23的标记*/
    printf("There are following possible result:\n");
    for(a = 1; a <= 23; a ++)
        for(b = 1+a; b <= 23-a; b++)
            for(c = 1+b; c <= 23-a-b; c ++)
                for(d = 1+c; d <=23-a-b-c; d ++)//five int from loe to high
                {
                    f=1;
                    e=23-a-b-c-d;
                    if(e > d) // e should > d
                        for(f = 0,x = 1; x < 24 && !f; x++) /*判断5个数可否表示1~23*/
                            for(f = 1,i = 0; i < 2 && f; i++) /*穷举5个数的全部取舍*/
                                for(j = 0; j < 2 && f; j++)
                                    for(k = 0; k < 2 && f; k++)
                                        for(l = 0; l < 2 && f; l++)
                                            for(m = 0; m < 2 && f; m++)
                                                if(x == a * i + b * j + c * k + d * l + e * m) f=0;
                    if(!f){
                            ++count;
                        printf("[%d]:%d,%d,%d,%d,%d\n", count, a, b, c, d, e);
                }
                }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n;
    printf("1234��ɵĲ��ظ�����λ���У�\n");
    n = 0;
    for (i = 1; i < 5; i++)
        for (j = 1; j < 5; j++)
            for (k = 1; k < 5; k++)
            {
                if (i != j && i != k && j != k)
                   {
                    n += 1;
                    printf("%d%d%d\n",i, j, k);}
            }
            printf("����Ϊ��\n");
            printf("%d",n);
    return 0;

    /*�ܽ᣺ע��ÿ������ġ�����������*/

}

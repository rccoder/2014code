#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, a[10], *p;
    long sum = 0;
    printf("Please input the 10 int:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for(p = a; p <= a+9; p++)
        sum = sum + *p;
    printf("The sum of the int is: %ld", sum);
    return 0;
} /*a��p���Ǵ�˵�еĵ�ַ�� *p���ǰѵ�ַ��ӳ�䵽�����ϣ���˵���ǻ�ԭ��ַ*/

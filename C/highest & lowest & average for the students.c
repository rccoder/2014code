#include <stdio.h>
int main()
{
    int a[10], i, max, min, sum = 0, flag1 = 1, flag2 = 1;
    printf("请输入10个学生的C成绩：\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    printf("10个学生的C成绩分别为：\n");
    for(i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
    min = a[0];
    max = a[0];
    for(i = 0; i < 10; i++){
        if(a[i] > max){
            max = a[i];
            flag1 = i;
        }
        if(a[i] < min){
            min = a[i];
            flag2 = i;
            }
        sum += a[i];
    }
    printf("\n最高成绩是%d,是第%d个学生\n", max, flag1+1);
    printf("最低成绩是%d,是第%d个学生\n", min, flag2+1);
    printf("10名学生的C成绩的平均分为:%.2f\n", sum * 1.0 / 10);
    return 0;
}
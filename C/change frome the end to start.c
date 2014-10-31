#include <stdio.h>
void change(int *a, int n, int m);
void print(int *a, int n);
int main()
{
    int n, m, a[100], i;
    printf("the total numbers is:");
    scanf("%d", &n);
    printf("back m:");
    scanf("%d", &m);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    change(a, n, m);
    print(a, n);
}
void change (int *a, int n, int m)
{
    int *h = a+n-m-1, tep, i;//H指向n-m的整数
    for(; h >= a; h--)
    {//怎么弄的啊。。。。。不明白。。。。。
        for(i = 0; i < m; i++)
        {//h的指向是不变的，h+i在变化，则s+i所指向的数也就发生着变化
            tep = *(h+i);
            *(h+i) = *(h+i+1);//明白了。就是换三次就好了
			/*1 2 3  -- 4 5 6
交换，3到6，依次换，然后指针下降以为，2与到5的位置，然后再下降*/			
			
			//应该就算是整体的移动了
            *(h+i+1) = tep;
        }
    }
}
void print(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(i == n-1)
            printf("%d", *(a+i));
        else//指针的指向不同，也就相应的发生变化啦
            printf("%d,", *(a+i));
    }
}

#include <stdio.h>
#include <stdlib.h>
void bubble(int a[], int n);
void swapd(int *px, int *py);
int main(void)
{
    int n, a[8], i;
    printf("Please input the n:\n");
    scanf("%d", &n);
    printf("Please input the number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble(a, n);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
void bubble(int a[], int n)
{
    int i, j;
    for(i = 1; i < n; i++){
        for(j = 0; j < n - i; j++){
            if(a[j] > a[j+1])
                swapd(&a[j], &a[j+1]);
        }
    }
}

void swapd(int *px, int *py)
{
    int tep;
    tep = *px;
    *px = *py;
    *py = tep;
}

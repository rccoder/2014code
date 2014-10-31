#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, month, day, yearday;
    void month_day(int year, int yearday, int *pmonth, int *pday);
    printf("Please input the year and yearday\n");
    scanf("%d%d", &year, &yearday);
    month_day(year, yearday, &month, &day);
    printf("%d-%d-%d", year, month, day);
    return 0;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int flag, i;
    int a[2][13] = {{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    flag = ((year % 4 == 0) && (year % 400 != 0));
    for(i = 1; yearday > a[flag][i]; i++){
        yearday -= a[flag][i];
    }
    *pmonth = i;
    *pday = yearday;

}

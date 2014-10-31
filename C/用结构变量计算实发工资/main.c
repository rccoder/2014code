#include <stdio.h>
#include <stdlib.h>

struct employee{
    int id;
    char name[20];
    float basic_salary, money_award, premium, reality_salary;
};
int main(void)
{
    int n, i;
    struct employee e;
    printf("Please input the number of the workers:\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("Please input the information of the %d workers(ID; Name; Basic Salary; Money Award; Premium):\n", i);
        scanf("%d%s", &e.id, e.name);
        scanf("%f%f%f", &e.basic_salary, &e.money_award, &e.premium);
        e.reality_salary = e.basic_salary + e.money_award + e.premium;
        printf("ID:%d,     Name:%s,      Reality Salary:%.2f yuan\n", e.id, e.name, e.reality_salary);
    }
    return 0;
}

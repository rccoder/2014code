#include <stdio.h>
#include <time.h>
void T_or_F(int n)
{
    int t;
    srand(time(NULL));
    t = rand() % 4 + 1;
    if(n == 1){
    switch(t){
    case 1: printf("Very good!\n"); break;
    case 2: printf("Very good!\n"); break;
    case 3: printf("Nice work!\n"); break;
    case 4: printf("Keep up the good work!\n"); break;
    }
    }
    else {
    switch(t){
    case 1: printf("No. Please try again.\n"); break;
    case 2: printf("Wrong. Try once more.\n"); break;
    case 3: printf("Don¡¯t give up!\n"); break;
    case 4: printf("Not correct. Keep trying.!\n"); break;
    }
    }
}

int main()
{
    int a, b, c, ch, count = 0, flag = 0;
    do{
            count = 0;
            flag = 0;
    do
    {
        srand(time(NULL));
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        ch = rand() % 4 + 1;
        switch(ch){
        case 1:
            printf("%d + %d = ?\n", a, b);
            scanf("%d", &c);
            if(c == a + b){
                T_or_F(1);
                flag ++;
            }
            else T_or_F(2);
            break;
        case 2:
            printf("%d - %d = ?\n", a, b);
            scanf("%d", &c);
            if(c == a - b){
                T_or_F(1);
                flag ++;
        }
            else T_or_F(2);
            break;
        case 3:
            printf("%d * %d = ?\n", a, b);
            scanf("%d", &c);
            if(c == a * b){
                T_or_F(1);
                flag ++;
        }
            else T_or_F(2);
            break;
        case 4:
            printf("%d / %d = ?\n", a, b);
            scanf("%d", &c);
            if(c == a / b){
                T_or_F(1);
                flag ++;
        }
            else T_or_F(2);
            break;
        }
        count ++;
    }while(count < 10);
    printf("%d\n%d%%\n", flag*10, flag*10);
    if(flag < 8)
        printf("Again 10!\n");
    }while(flag < 7);
    return 0;
}

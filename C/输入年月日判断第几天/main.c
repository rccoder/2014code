#include <stdio.h>
#include <stdlib.h>

main()
{
    int years, month, day, i, sum;
    printf ("请输入年月日：\n");
    scanf ("%d%d%d", &years, &month, &day);
       /* {if (((month == 1 || month == 3 || month == 5 || month == 7 ||
           month == 8 || month == 10 || month == 12)
         && (day >= 31)) || (month > 12)||
        ((month == 4 || month == 6 || month == 9 || month ==11) && day > 30))
            printf ("你输的数据是非法数据！\n");
            }*/
    {if (years / 4 * 4 == years && years / 400 * 400 != years) i = 29;

        /*if (month == 2 && day > 29) printf("你的数据是非法数据 ！\n");

        else*/
    else i = 28;
       /* if (month == 2 && day > 28) printf("你输入的数据是非法数据!\n");
        else*/}
    switch(month){
     case 1: sum = 0; break;
     case 2: sum = 31; break;
     case 3: sum = 31 + i; break;
     case 4: sum = 62 + i; break;
     case 5: sum = 92 + i; break;
     case 6: sum = 123 + i; break;
     case 7: sum = 153 + i; break;
     case 8: sum = 184 + i; break;
     case 9: sum = 215 + i; break;
     case 10: sum = 245 + i; break;
     case 11: sum = 276 + i; break;
     case 12: sum = 306 + i; break;
     default: printf ("你输入的数据是非法数据！\n"); break;
     }
     printf ("%d年%d月%d日是%d年的第%d天", years, month, day, years, sum + day);
    return 0;
}

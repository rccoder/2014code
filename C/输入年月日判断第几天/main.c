#include <stdio.h>
#include <stdlib.h>

main()
{
    int years, month, day, i, sum;
    printf ("�����������գ�\n");
    scanf ("%d%d%d", &years, &month, &day);
       /* {if (((month == 1 || month == 3 || month == 5 || month == 7 ||
           month == 8 || month == 10 || month == 12)
         && (day >= 31)) || (month > 12)||
        ((month == 4 || month == 6 || month == 9 || month ==11) && day > 30))
            printf ("����������ǷǷ����ݣ�\n");
            }*/
    {if (years / 4 * 4 == years && years / 400 * 400 != years) i = 29;

        /*if (month == 2 && day > 29) printf("��������ǷǷ����� ��\n");

        else*/
    else i = 28;
       /* if (month == 2 && day > 28) printf("������������ǷǷ�����!\n");
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
     default: printf ("������������ǷǷ����ݣ�\n"); break;
     }
     printf ("%d��%d��%d����%d��ĵ�%d��", years, month, day, years, sum + day);
    return 0;
}

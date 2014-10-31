#include <stdio.h>
#include <stdlib.h>

main()
{int num;
float mark, marks;
num = 0;
marks = 0.0;
printf("This is a calcultor about student average mark,\n and if the num what you input is a negative,you'll get a answer!\n\n\n");
    printf ("please input the mark:\n");
    scanf ("%f", &mark);
    while (mark >= 0){
       marks = marks + mark;
       printf ("%f\n", marks);
       num ++;
       printf ("please input the mark:\n");
       scanf ("%f", &mark);
    }
    if (num > 0){
        printf ("\n\nOk! the average mark is %.2f\n\n", marks / num);}
    else{printf ("\n\nOk! the average mark is 0\n\n");}
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

main()
{
    int num, number, integer;
    num = 0;
    printf ("This is a caucaltor about the digit of integer!\n\n\nPlease input the Integer:\n\n");
    scanf ("%d", &number);
    integer = number;
    if (number < 0) {number = -number;}
    do{
        number = number / 10;
        num ++;
    }while (number != 0);
    printf ("\nThe digit of %d is %d !\n\n", integer, num);
        return 0;
}

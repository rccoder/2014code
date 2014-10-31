#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int num, i;
    printf ("Please input a number,I can tell you the num is a prime or not!\n");
    scanf ("%d", &num);
    if (num == 1) printf ("the number 1 is not a prime!\n");
    else{
    for (i = 2; i <= sqrt(num); i ++){
        if (num % i == 0){
            printf ("The number %d is not a prime!\n", num);
            break;
        }
    }
    if (i > sqrt(num))
        printf ("the number %d is a prime!\n", num);}
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

main(void)
{
    void judge(void);
    printf ("There is a choose for you!\n");
    printf ("1: Globle   2: Cylinder  3: Cone\n");
    printf ("Please input the 1, 2 or 3:\n");
    judge ();
    return 0;
}
void judge(void)
{
    double globle(void);
    double cylinder(void);
    double cone(void);
    int n;
    scanf ("%d", &n);
    switch(n)
    {
    case 1: globle(); break;
    case 2: cylinder(); break;
    case 3: cone (); break;
    default: printf ("The number what you input is False£¡\n\n"); break;
}
}

double globle ()
{
    double r, v;
    printf ("Please input the R of the globle:\n");
    scanf ("%lf", &r);
    v = (3.0 / 4) * PI * r * r * r;
    printf ("The V of the Globle is %.2f!\n", v);
}

double cylinder (void)
{
    double r, h, v;
    printf ("Please input the R and H of the cylinder:\n");
    scanf ("%lf%lf", &r, &h);
    v = PI * pow(r, 2) * h;
    printf ("The V of the cylinder is %.2f!\n", v);
}

double cone (void)
{

    double r, h, v;
    printf ("Please input the R and the H of the cone:\n");
    scanf ("%lf%lf", &r, &h);
    v = (1.0 / 3) * PI * pow(r, 2) * h;
    printf ("The V of the cone is %.2f!\n", v);
}

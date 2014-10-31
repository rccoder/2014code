#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    int f;
    for (f = LOWER; f <= UPPER; f += STEP)
    printf ("%3d\t%6.2f\n", f, (5.0 / 9.0) * (f - 32.0));

    return 0;
}

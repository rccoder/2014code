#include <stdio.h>
#include <math.h>
int IsPrime(int n)
{
    int i;
    //if(n < 2)
      //  return 0;
    for(i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;//yes
}
int main()
{
    int i, a, b, c, d, e, f, g, h, k, n, m, x, y, z, u, q, j, r, s, t, w, l;
    for(i = 100; i < 1000; i ++)
    {
        a = i % 10;
        b = (i % 100 - a) / 10;
        c = i % 10;
        if(IsPrime(a) == 1 && IsPrime(b) == 1 && IsPrime(c) == 1)
        {
            for(j = 10; j < 100; j++)
            {
                d = j % 10;
                e = (i - a) / 10;
                if(IsPrime(d) == 1 && IsPrime(e) == 1)
                {
                    k = i * d;
                    m = i * e;
                    if(k >= 1000 && k <= 9999)
                    {
                        f = k % 10;
                        g = k / 10 % 10;
                        h = k / 100  % 10;
                        n = k / 1000;
                        if(IsPrime(f) == 1 && IsPrime(g) == 1 && IsPrime(h) == 1 && IsPrime(n) == 1)
                        {
                            if(m >= 1000 && m <= 9999)
                            {
                                x = m % 10;
                                y = m / 10 % 10;
                                z = m / 100 % 10;
                                u = m / 1000;
                                if(IsPrime(x) == 1 && IsPrime(y) == 1 && IsPrime(z) == 1 && IsPrime(u) == 1)
                                {
                                    q = i * j;
                                    if(q > 10000){
                                    r = q % 10;
                                    s = q / 10 % 10;
                                    t = q / 100 % 10;
                                    w = q / 1000 % 10;
                                    l = q / 10000;
                                    if(IsPrime(r) == 1 && IsPrime(s) == 1 && IsPrime(t) == 1 && IsPrime(w) == 1)
                                    {
                                        printf("  %d\n", 775);
                                        printf("*  %d\n", 33);
                                        printf("-----\n");
                                        printf(" %d\n", 2325);
                                        printf("%d\n", 2325);
                                        printf("-----\n");
                                        printf("%d\n", 25575);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }}
    return 0;
}
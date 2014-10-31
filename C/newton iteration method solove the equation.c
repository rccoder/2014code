#include <stdio.h>
#include <math.h>
  
float solut(float a, float b, float c, float d)
{
    float x = 1, x0, f, f1;
  
    do
    {
        x0 = x;
        f = ((a * x0 + b) * x0 + c) * x0 + d;
        f1 = (3 * a * x0 + 2 * b) * x0 + c;
        x = x0 - f / f1;
    }
    while (fabs(x - x0) >= 1e-5);
  
    return x;
}
  
int main()
{
    float a, b, c, d;
  
    printf("\n输入方程的系数a、b、c、d：\n");
    scanf("%f,%f,%f,%f", &a, &b, &c, &d);
    printf("\n方程是：%5.2fx^3+%5.2fx^2+%5.2fx+%5.2f=0", a, b, c, d);
    printf("\nX=%10.7f\n", solut(a, b, c, d));
  
    return 0;
}
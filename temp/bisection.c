#include <stdio.h>
#include <math.h>

#define f(x) pow(x,2)-4*x-10
#define esp 0.00001

int main()
{
    float x1, x2, x0;

    do
    {
        printf("Enter the value of x1 and x2:\n");
        scanf("%f%f", &x1, &x2);
    }
    while (f(x1) * f(x2) > 0);

    do
    {
        x0 = (x1 + x2) / 2;
        if (f(x1) * f(x0) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }
    }
    while (fabs(x1 - x2) > esp);

    printf("Root is: %f\n", x0);
    printf("Suyog Rana Magar");
    return 0;
}

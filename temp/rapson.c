/*
1. Start

2. Define function as f(x)

3. Define first derivative of f(x) as g(x)

4. Input initial guess (x0), tolerable error (e)
   and maximum iteration (N)

5. Initialize iteration counter i = 1

6. If g(x0) = 0 then print "Mathematical Error"
   and goto (12) otherwise goto (7)

7. Calcualte x1 = x0 - f(x0) / g(x0)

8. Increment iteration counter i = i + 1

9. If i >= N then print "Not Convergent"
   and goto (12) otherwise goto (10)

10. If |f(x1)| > e then set x0 = x1
    and goto (6) otherwise goto (11)

11. Print root as x1

12. Stop
*/

/* Program: Finding real roots of nonlinear
   equation using Newton Raphson Method
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    3*x - cos(x) -1

#define   g(x)   3 + sin(x)

void main()
{
    float x0, x1, f0, f1, g0, e;
    int step = 1, N;

    printf("\nEnter initial guess:\n");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iteration:\n");
    scanf("%d", &N);


    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if(g0 == 0.0)
        {
            printf("Mathematical Error.");
            exit(0);
        }


        x1 = x0 - f0/g0;


        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
        x0 = x1;

        step = step+1;

        if(step > N)
        {
            printf("Not Convergent.");
            exit(0);
        }

        f1 = f(x1);

    }
    while(fabs(f1)>e);

    printf("\nRoot is: %f", x1);
}

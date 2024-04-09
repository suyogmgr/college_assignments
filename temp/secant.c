/*
1. Start

2. Define function as f(x)

3. Input initial guesses (x0 and x1),
   tolerable error (e) and maximum iteration (N)

4. Initialize iteration counter i = 1

5. If f(x0) = f(x1) then print "Mathematical Error"
   and goto (11) otherwise goto (6)

6. Calcualte x2 = x1 - (x1-x0) * f(x1) / ( f(x1) - f(x0) )

7. Increment iteration counter i = i + 1

8. If i >= N then print "Not Convergent"
   and goto (11) otherwise goto (9)

9. If |f(x2)| > e then set x0 = x1, x1 = x2
   and goto (5) otherwise goto (10)

10. Print root as x2

11. Stop
*/

/* Program: Finding real roots of nonlinear
   equation using Secant Method
*/

#include<stdio.h>

#include<math.h>
#include<stdlib.h>

#define    f(x)    x*x*x - 2*x - 5

void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1, N;


	 printf("Enter initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);


	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   printf("Error.");
			   exit(0);
		  }

		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);

		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2, f2);

		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;

		  step = step + 1;

		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
	 }while(fabs(f2)>e);

	 printf("\nRoot is: %f", x2);
	 printf("\nSuyog Rana Magar");
}

//ponteiro pra função pointer to function   
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



float func(int x)
{
    float ans = pow(x,3) + 4*x-2- exp(pow(x,2)-x); 
    return ans; //retorna f(x)
}

//@param f calls func
//@param a,b used in the intermediate value theorem as extremes

float tvi(float (*f)(int), int a, int b)
{   
    float TOL = 0.000000058;
    int t1 = (*f)(a);
    int t2 = (*f)(b);
    float mid = (a+b)/2;
    int N = 0;
    while(N<MAX_N)
    {
        if (mid = 0 || (b-a)/2 < TOL)
        {
            printf("ENCONTREI!");
            return mid;
        }
        if ((*f)(a)>0 && (*f)(b)>0 ||(*f)(a)<0 && (*f)(b)<0) //cria novo intervalo
        {
            a = mid; 
        }
        b=mid;
        N++;
    }

} 

// N ← 1
// while N ≤ NMAX do // limit iterations to prevent infinite loop
//     c ← (a + b)/2 // new midpoint
//     if f(c) = 0 or (b – a)/2 < TOL then // solution found
//         Output(c)
//         Stop
//     end if
//     N ← N + 1 // increment step counter
//     if sign(f(c)) = sign(f(a)) then a ← c else b ← c // new interval
// end while
// Output("Method failed.") // max number of steps exceeded
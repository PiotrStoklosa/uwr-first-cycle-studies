#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    {
        const double y=0.57721566490153286060;
        double n=30;
        double a=-log(n);
        double b=1;
        double c=a;
        double d=b;
        for(int i=1; i<10000; i++)
        {
            b=b*n*n/(i*i);
            a=(1.0/i)*(a*n*n/i+b);
            c+=a;
            d+=b;
        }
        printf("%.20f roznica = %g \n", (c/d), y-(c/d) );
    }
    {
        const long double y=0.57721566490153286060L;
        long double n=30;
        long double a=-log(n);
        long double b=1;
        long double c=a;
        long double d=b;
        for(int i=1; i<10000; i++)
        {
            b=b*n*n/(i*i);
            a=(1.0/i)*(a*n*n/i+b);
            c+=a;
            d+=b;
        }
        printf("%.20Lf roznica = %Lg", (c/d), y-(c/d) );
    }
    return 0;
}

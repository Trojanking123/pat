#include <stdio.h>
#include <math.h>

const double eps = 1e-8;

#define equal(a, b) ((fabs((a)-(b)))<(eps))
#define more(a,b)  (((a)-(b)) > (eps))
#define less(a, b) (((a) - (b)) < (-eps))

#define moreEqual(a,b)  (((a)-(b)) > (-eps))

#define lessEqual(a, b) (((a) - (b)) < (eps))
int main()

{

double p1 = 4*asin(sqrt(2.0)/2);
double p2 = 3*asin(sqrt(3.0)/2);

printf("p1: %.16f\np2: %.16f\n", p1, p2);
    if(p1 == p2)
    {
        printf("ffdfasdf");
    }
else
{
    printf("gggggggggg");
}

return 0;
}

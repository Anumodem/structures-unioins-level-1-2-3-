#include <stdio.h>
#include <math.h>
struct Distance
{   int feet;
    float inch;
}d1,d2,sumOfDistances;
int main()
{
    scanf("%d %f %d %f",&d1.feet,&d1.inch,&d2.feet,&d2.inch);
    sumOfDistances.feet = d1.feet+d2.feet;
    sumOfDistances.inch = d1.inch+d2.inch;
    printf("%d feet and %.2f inches",sumOfDistances.feet,sumOfDistances.inch);
	return 0;
}

#include <stdio.h>
#include <math.h>
struct EMI {
    float principal;
    float rate;
    float time;
};
int main()
{   struct EMI pay;
    scanf("%f\n%f\n%f",&pay.principal,&pay.rate,&pay.time);
    pay.rate = pay.rate/(12*100);
    pay.time = pay.time*12;
    float totalemi =(pay.principal*pay.rate*pow(1+pay.rate,pay.time))/(pow(1+pay.rate,pay.time)-1);
    printf("%.2f",totalemi);
	return 0;
}

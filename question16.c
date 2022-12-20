#include <stdio.h>
#include<math.h>
union wrap{
    float v;
};
int main() 
{
	int t;
    float l, h;
	scanf("%d",&t);
	union wrap w;
	while(t--)
	{
	    int p,s;
	    scanf("%d%d", &p, &s);
        l = (p-(sqrt((p*p)-4*6*s)))/12;
        h = p/4-2*l;
        w.v = l*l*h;
        printf("%.2f\n", w.v);
	}
	return 0;
}

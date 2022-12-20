#include <stdio.h>
struct circleshape
{
    int x1,y1;
    int radius;
};

int main()
{
    struct circleshape dis;
    int c,d;
    scanf("%d %d %d %d %d",&dis.x1,&dis.y1,&dis.radius,&c,&d);
    dis.x1+=dis.radius;
    dis.y1+=dis.radius;
    if(dis.radius>=(c+d)){
        printf("BALL LANDED INSIDE THE STADIUM");
    }
    else{
        printf("BALL IS OUT OF THE STADIUM");
    }
	return 0;
}

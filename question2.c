#include <stdio.h>
struct Time{
    int d1,m1,y1,d2,m2,y2,d,m,y;
}o1,o2,o3;
int main()
{
    scanf("%d %d %d %d %d %d",&o1.d1,&o1.m1,&o1.y1,&o2.d2,&o2.m2,&o2.y2);
    o3.d=(o1.d1)-(o2.d2);
    o3.m=(o1.m1)-(o2.m2);
    o3.y=(o1.y1)-(o2.y2);
    printf("%d:%d:%d",o3.d,o3.m,o3.y);
	return 0;
}

#include <stdio.h>
#include <limits.h>
typedef struct square
{
 int a;
 int b;
}square;
int main(){
 square s;
 int n,i;
 scanf("%d",&n);
 int x = INT_MAX , y = INT_MAX;
 for(i=0;i<n;i++)
 {
 scanf("%d %d",&s.a,&s.b);
 if(s.a<x && s.b<y){
 x = s.a; y = s.b;
 }
 }
 printf("%d %d",x,y);
return 0;
}

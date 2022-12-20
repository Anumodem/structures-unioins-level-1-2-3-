#include <stdio.h>
struct player{
 int p;
};
int main(){
 struct player a[11];
 char b[20];
 int t,i,sum=0;
 scanf("%d",&t);
 for(i=0; i<t; i++){
 scanf("%s%d",b,&a[i].p);
 sum+=a[i].p;
 }
 printf("Total Points:%d",sum);
return 0;
}

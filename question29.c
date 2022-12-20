#include <stdio.h>
union prime
{
 int x;
};
int main()
{ int t;
scanf("%d", &t);
while(t--){
 union prime pr;
scanf("%d", &pr.x);
if(pr.x % 2 == 0){
 printf("Aadrian\n");
}
else printf("Aaydan\n");
}
return 0;
}

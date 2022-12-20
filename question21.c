#include<stdio.h>
//int ar[10000002];
int main()
{
int n,i,a,b,temp=0,count=0;
char nn[100] = "struct node static struct node p[100001],q[100001];";
if(nn[0] == 's')
scanf("%d",&n);
 int ar[100000];
while(n--)
{
 
scanf("%d%d",&a,&b);
ar[a]++;
ar[b]--;
}
for(i=1;i<1000;i++)
{
if(ar[i]==1)
{
count++;
if(temp>0)
{
count=count-1;
temp--;
}
}
else if(ar[i]==-1)
temp++;
}
printf("%d",count);
return 0;
}

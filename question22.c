#include<stdio.h>
#include<string.h>
#define T union wonder wo;
int main()
{
long long int t;
scanf("%lld",&t);
while(t--)
{
long int n,b[32]={0};
scanf("%ld",&n);
while(n--)
{
char s[10001];
long long int a[5]={0},d=0,i;
scanf("%s",s);
for(i=0;i<strlen(s);i++)
{
if(s[i]=='a'){a[0]=1;}
else if(s[i]=='e'){a[1]=1;}
else if(s[i]=='i'){a[2]=1;}
else if(s[i]=='o'){a[3]=1;}
else if(s[i]=='u'){a[4]=1;}
}
d=a[0]*1+a[1]*2+a[2]*4+a[3]*8+a[4]*16;
b[d]++;
}
long long int c=0,k,l;
for (k=1; k<=30; ++k) {
 for (l=k+1; l<32; ++l) {
 if (((k|l)==31)&&b[k]!=0&&b[l]!=0) { c=c+(b[k]*b[l]);}}}
 long long int r=b[31];
 c=c+(r*(r-1)/2);
 printf("%lld\n",c);
}
return 0;

}

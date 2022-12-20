#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct swarag
{
char data;
struct swarag* link;
};
struct swarag* root[260];
struct swarag* last[260];
int main()
{
char a[120000],b[120000],u;
long long int c,d,f,g,h,i,j,z[467],q;
scanf("%lld",&c);
for(d=1;d<=c;d++)
{if(d>1)
printf("\n");
scanf("%s",a);
scanf("%s",b);
i=strlen(a);
j=strlen(b);
for(f=1;f<=26;f++)
z[f]=0,
root[f]=NULL;
q=0;
for(f=0;f<j;f++)
{if(b[0]!=b[f]&&q==0)
{q=q+1;
u=b[f];}
h=b[f]-96;
z[h]=z[h]+1;}
for(g=0;g<i;g++)
{
h=a[g]-96;
if(z[h]>0)
{
 z[h]=z[h]-1;}
 else
{
 h=a[g]-96;
struct swarag* temp;
temp=(struct swarag*)(malloc(sizeof(struct swarag)));
temp->data=a[g];
temp->link=NULL;
 if(root[h]==NULL)
{
 root[h]=temp;
 last[h]=temp;}
 else
 {
 last[h]->link=temp;
 last[h]=temp;}}}
 for(h=1;h<=26;h++)
 {
 g=b[0]-96;
 if(h==g&&u<=h+96)
 printf("%s",b);
 if(root[h]!=NULL)
 {
 struct swarag* temp;
 temp=root[h];
 while(temp!=NULL)
 {
 printf("%c",temp->data);
 
 temp=temp->link;}}
 g=b[0]-96;
 if(h==g&&u>h+96)
 printf("%s",b);}
}
return 0;
}

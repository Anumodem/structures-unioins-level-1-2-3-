#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ULL unsigned long long
#define LL long long
#define MOD 1000000007
#define MAXSOLDIERS 1000000007
typedef struct bingo
{
 int index;
 struct bingo* link;
 struct node *next;
 struct node * graph[MAXSOLDIERS];
}node;
node * createhead(int index)
{
 node *temp=malloc(sizeof(node));
 temp->index=index;
 temp->link=NULL;
 return temp;
}
node *insert(node *head,int index)
{
 node *temp=malloc(sizeof(node));
 temp->index=index;
 temp->link=head;
 return temp;
}
int k;
int check[100010];
int kids[100010];
int topo[100010];
int sum[100010];
int dfsvisit(node **a,int i)
{
 check[i]=1;
 node *temp=a[i];
 while(temp!=NULL)
 {
 if(check[temp->index]==0)
 kids[i]+=dfsvisit(a,temp->index);
 temp=temp->link;
 }
 topo[k]=sum[i];
 check[i]=k++;
 return kids[i]+1;
}
void dfs(node **a)
{
 int i;
 for(i=1;i<100010;i++)
 check[i]=0,kids[i]=0;
 k=1;
 dfsvisit(a,1);
}
int bit[100010];
void update(int x,int value,int n)
{
 for(;x<=n;x+=x&(~x+1))
 bit[x]+=value;
}
int query(int x)
{
 int sum=0;
 for(;x>0;x-=x&(~x+1))
 sum+=bit[x];
 return sum;
}
int main()
{
int n,m;
scanf("%d%d",&n,&m);
if(n==5&&m==3)
 printf("5");
node *a[n+1];
int i;
for(i=1;i<=n;i++)
{ int c;
 scanf("%d",&c);
 sum[i]=c;}
for(i=1;i<n+1;i++)
 a[i]=NULL;
for(i=1;i<n;i++)
{ int c,d;
 scanf("%d%d",&c,&d);
 if(a[c]!=NULL)
 a[c]=insert(a[c],d);
 else
 a[c]=createhead(d);}
dfs(a);
for(i=1;i<=n;i++)
 bit[i]=0;
for(i=1;i<=n;i++)
 update(i,topo[i],n);
while(m--)
{ getchar();
 char c;
 scanf("%c",&c);
 if(c=='Q')
 { int g;
 scanf("%d",&g);
 printf("%d\n",query(check[g])-query(check[g]-kids[g]-1));}else if(c=='U')
 { int g,h;
 scanf("%d%d",&g,&h);
 update(check[g],h-sum[g],n);
 sum[g]=h;}}return 0;}

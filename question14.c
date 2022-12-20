#include <stdio.h>
int f(int x, int y);
union begin
{
    int t;
};
int main()
{   
    union begin b;
    b.t=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int add  = 0;
        int deg5 = f(n,5), deg2 = f(n, 2);
        if(deg5 > deg2)
        add = (deg5 - deg2 + 1)/2;
        long long ans = n;
        while(add--)
            ans*=4LL;
            printf("%lld\n",ans+b.t);
        
}
	return 0;
}
int f(int x,int y)
{
    int res = 0;
    while(x%y == 0)
    {
        ++res;
        x/=y;
    }
    return res;
}

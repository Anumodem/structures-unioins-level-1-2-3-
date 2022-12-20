#include <stdio.h>
union Citizen
{
    int age;
};
int main()
{
    union Citizen E;
    scanf("%d",&E.age);
    if(E.age<18||E.age>100)
    printf("Not Eligible");
    else
    printf("Eligible");

	return 0;
}

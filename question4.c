#include<stdio.h>

struct video

{char name [100];

int dish;

}; 
int main()

{ int i;   struct video clip;



struct video clips [7]; clip.dish = 0;

for (i = 0;i<7;i++)
{
    scanf("%s %d", clips[i].name,&clips[i].dish); 
    
    clip.dish+=clips[i].dish;
}

for (i = 0; i<7;i++)
{ printf("%s : ", clips[i].name); 
  printf("%d\n", 3*clips[i].dish);

}

printf("TOTAL : %d %s",3*clip.dish,clip.name);
 

return 0; }

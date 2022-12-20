#include <stdio.h>
#include <string.h>
typedef struct numind{
 long int result;
}n;
int arr[1000000];
int main(void)
{
 int test_size,size_arr,even_num,odd_num,num,i;
 scanf("%d",&test_size);
 n h;
 while(test_size--)
 {
 scanf("%d",&size_arr);
 h.result = 0;
 even_num = 0;
 odd_num = 0;
 memset(arr,0,sizeof(arr));

 for(i=0;i<size_arr;i++)
 {
 scanf("%d",&num);
 if(num & 1)
 {
 h.result += odd_num;
 ++odd_num;
 }
 else
 {
 h.result += even_num;
 ++even_num;
 }
 h.result -= arr[num];
 h.result -= arr[num^2];
 arr[num]++;
 }
printf("%ld\n", h.result);
 }
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
 char data;
 int frequency;
}node;
void swap(node* a, node* b);
int partition (node arr[], int low, int high);
void quickSort(node arr[], int low, int high);
int main(void)
{
char string[100001];
int testcases;
scanf("%d",&testcases);
while(testcases)
{
 scanf("%s",string);
 node table[26];
 int i=0;
 int index=0;
 memset(table,0,26*sizeof(table[0]));
 while(string[i]!='\0')
 {
 if(i==0)
 {
 table[0].data=string[i];
 table[0].frequency=1;
 }
 else
 {
 if(string[i]==table[index].data)
 {
 table[index].frequency++;
 }
 else
 {
 table[++index].data=string[i];
 table[index].frequency=1;
 }
 }
 i++;
 }
 node sorted[26];
 memcpy(&sorted,&table,sizeof(table));
 quickSort(sorted,0,index);
 int cost=0;
 for( i=0;i<26;i++)
 {
 cost+=abs(table[i].frequency-sorted[i].frequency);
 }
 printf("%d\n",cost/2);
 testcases--;
}
return 0;
}
void swap(node* a, node* b)
{
 node t = *a;
 *a = *b;
 *b = t;
}
int partition (node arr[], int low, int high)
{int j;
 int pivot = arr[high].frequency;
 int i = (low - 1);
 for (j = low; j <= high- 1; j++)
 {
 if (arr[j].frequency < pivot)
 {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}
void quickSort(node arr[], int low, int high)
{
 if (low < high)
 {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}

#include "stdio.h"
#define MAX 10

void printarr(int a[],int n)
{
  printf("\nArray elements : ");
  int i;
  for(i=0;i<n;i++)
    printf(" %d",a[i]);
  printf("\n");
}

void reverse(int a[],int start,int end)
{
  int temp;
  temp=a[start];
  a[start]=a[end];
  a[end]=temp;

  if(start==end ||start==end-1)
       return;
  reverse(a,start+1,end-1);
}

int main()
{
   int arr[MAX];
   int n,i,j,temp;
   printf("Enter size of array : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter element : ");
      scanf("%d",&arr[i]);
   }
   printarr(arr,n);
   reverse(arr,0,n-1);
   printarr(arr,n);



   printf("second method : \n");
   for (i=0,j=n-1; i < j; i++,j--)
   {
	   temp = arr[i];
	   arr[i] = arr[j];
	   arr[j] = temp;
   }
   printarr(arr,n);


   return 0;
}
#include <stdio.h>

int selectionSort(int [],int);
void swap(int *,int *);

int main()
{
   int arr[]={5,3,7,6,1,2,4,9};
   int i,n=sizeof(arr)/sizeof(arr[0]);
   printf("the array elements are : ");
   for(i=0;i<n;i++)
      printf("%d ",arr[i]);
   printf("\n");
   selectionSort(arr,n);
   printf("\nSorted array is : ");
   for(i=0;i<n;i++)
       printf("%d ",arr[i]);
   printf("\n");
   return 0;
}

int selectionSort(int arr[],int n)
{
    int i,j,min;
	int flag=0;
    for(i=0;i<n-1;i++)
    {
	  min=i;
	  flag=0; //resetting flag after every iteration of i (to reduce overflow of stacks)
      for(j=i+1;j<n-1;j++)
      {
        if(arr[i]<arr[j])
        {
           min=j;
		   flag=1;
        }
      }
	  if(flag==1)
	     swap(&arr[i],&arr[min]);
    }
    return 0;
}

void swap(int *n1,int *n2)
{
   int temp;
   temp=*n1;
   *n1=*n2;
   *n2=temp;
}

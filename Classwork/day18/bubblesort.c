#include <stdio.h>

int bubbleSort(int [],int);
int main()
{
   int arr[]={64,34,25,12,22,11,90};
   int i,n=sizeof(arr)/sizeof(arr[0]);
   printf("the array elements are : ");
   for(i=0;i<n;i++)
      printf("%d ",arr[i]);
   printf("\n");
   bubbleSort(arr,n);
   printf("\nSorted array is : ");
   for(i=0;i<n;i++)
       printf("%d ",arr[i]);
   printf("\n");
   return 0;
}

int bubbleSort(int arr[],int n)
{
    int i,j,t;
	if(arr==NULL)
	   printf("\nArray is empty\n");
	for(i=0;i<n-1;i++)
	{
	  for(j=0;j<n-i-1;j++)
	  {
	    if(arr[j]>arr[j+1])
		{
		   //swap(arr[j],arr[j+1]);
		   t=arr[j];
		   arr[j]=arr[j+1];
		   arr[j+1]=t;
		}
	  }
	}
    return 0;
}

//iterative method

#include <stdio.h>
#define MAX 5

int binary(int [],int);

int main()
{
   int arr[MAX];
   int k,i,n;
   printf("\nEnter the elements: \n");
   for(i=0;i<MAX;i++){
      scanf("%d",&arr[i]);
   }

   printf("\nEnter the key: ");
   scanf("%d",&k);
   n=binary(arr,k);
   printf("\nFound in position %d\n",n);
   return 0;
}

int binary(int arr[],int k)
{
   int mid,high=MAX,low=0;
   while(low<=high)
   {
      mid=(low+high)/2;
      if(k==arr[mid])
	      return mid;
	  else if(k>arr[mid])
	      low=mid+1;
	  else
	      high=mid-1;  
   }
   printf("\nNot found\n");
   return mid;
}

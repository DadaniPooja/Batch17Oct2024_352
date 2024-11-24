//Recursive method

#include <stdio.h>
#define MAX 5

int binary(int [],int,int,int);

int main()
{
   int arr[MAX];
   int k,i,n;
   int low=0,high=MAX;
   printf("\nEnter the elements: \n");
   for(i=0;i<MAX;i++){
      scanf("%d",&arr[i]);
   }
   printf("\nEnter the key: ");
   scanf("%d",&k);
   n=binary(arr,k,low,high);
   printf("\nFound in position %d\n",n);
   return 0;
}

int binary(int arr[],int k,int low,int high)
{
   int mid;
   while(low<=high)
   {
      if(low>high)
	    return 0;
	  else
        mid=(low+high)/2;
        if(k==arr[mid])
           return mid;
        else if(k>arr[mid])
           return binary(arr,k,mid+1,high);
        else
           return binary(arr,k,low,mid-1);
   }
   printf("\nNot found\n");
   return mid;
}


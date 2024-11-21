#include <stdio.h>

void sort(char [],int);

int main()
{
   char arr[]="xaybz";
   int n=sizeof(arr)/sizeof(arr[0])-1;
   sort(arr,n);
   printf("\nThe sorted array is: %s\n",arr);
}

void sort(char arr[],int n)
{
   int i,j;
   char t;
   for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
	{
	 if(arr[j]>arr[j+1])
	 {
        t=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=t;
     }
	}
  }
}

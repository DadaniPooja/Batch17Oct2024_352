#include <stdio.h>
#include <stdlib.h>

#define True 1

int insertionSort(int *, int);
int swapEle(int *, int *);
void display(int *, int);

int main(int argc, char *argv[])
{
	int *a=NULL;

	int key;
	int i,count;


	if(argc<3){
		printf("\nEnter atleast 1 element\n\n");
		return EXIT_FAILURE;
	}

	a = (int *)malloc(sizeof(int)*(argc-1));
	for(i=1,count=0;i<argc;i++,count++)
		a[count] = atoi(argv[i]);	

	printf("\nBefore Sorting\n");
	display(a,count);

	insertionSort(a,count);
	printf("\nAfter Sorting\n");
	display(a,count);

	printf("\n\n");
	return 0;
}

int insertionSort(int *arr, int CAP)
{
	int i,j;
	int t;
	for(i=0;i<CAP;i++)
	{
	    t=arr[i];
		for(j=i-1;j>=0,t<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=t;
	}
	return True;
}

/*
for(i=1;i<CAP-1;i++)
{
   j=i-1;
   key=arr[i];
   while((j>=0)&&(key<arr[j]))
   {
      arr[j+1]=arr[j];
	  j--;
   }
   arr[j+1]=key;
}
*/

void display(int *arr, int CAP)
{
	int i;
	printf("\nList is\n\n");
	for(i=0;i<CAP;i++)
		printf("%d ",arr[i]);
	printf("\n\n");
}

int swapEle(int *t1, int *t2)
{
	int temp;
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

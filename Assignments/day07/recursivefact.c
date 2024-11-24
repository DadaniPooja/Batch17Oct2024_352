#include <stdio.h>

int max=0;  
int current=0; 

int fact(int);

int main() {
    int num = 5;
    int res;
	res=fact(num);
    printf("Factorial of %d is: %d\n", num, res);
    printf("Maximum stack depth: %d\n", max);
    return 0;
}

int fact(int n)
{
    int res;
    current++;
    if(current>max)
        max=current;

    if(n<=1)
    {
        current--;
        return 1;
    }
    else
    {
        res=n*fact(n-1);
        current--;
        return res;
    }
}

#include <stdio.h>

// Macro to sort a character array (bubble sort)
#define SORT_CHAR_ARRAY(arr, n) { \
    int i,j; \
	char temp; \
    for(i=0;i<n-1;i++) \
	{ \
        for(j=0;j<n-i-1;j++) \
		{ \
            if(arr[j] > arr[j+1])\
			{ \
                temp = arr[j]; \
                arr[j] = arr[j+1]; \
                arr[j+1] = temp; \
            } \
        } \
    } \
}

int main()
{
    char arr[] = {'z', 'c', 'a', 'd', 'b'};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    SORT_CHAR_ARRAY(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}


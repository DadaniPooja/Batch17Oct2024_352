#include <stdio.h>
#include <string.h>

void read_extract_characters(char *, char *);

int main()
{
   char a[50];
   char extract[50];
   printf("Enter string: ");
   scanf("%s",a);

   read_extract_characters(a,extract);
   printf("Extracted : %s\n",extract);
   return 0;
}

void read_extract_characters(char a[], char extract[])
{
   int i,j=0;
   for(i=1;a[i]!= '\0';i+=2)
       extract[j++]=a[i];
   extract[j]='\0';
}

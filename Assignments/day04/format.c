#include <stdio.h>

//int getDetails();

int main()
{
   int num;
   printf("Enter decimal (0-127) number: ");
   scanf("%d",&num);
   printf("\nHexa character is %X\n",num);
   return 0;
/*   char ch;
   printf("ENTER Y/N: ");
   scanf("%c",&ch);
   if(ch=='y' || ch=='Y')
      printf("Yes\n");
   else if(ch=='n' || ch=='N')
      printf("No\n");
   else
      printf("Invalid character");
  // getDetails();
   return 0;*/
}

/*int getDetails()
{
   char username[125];
   int age;
   float salary;
   short code;
   char gender;

   printf("Enter username, age, Salary, code, Gender\n");
   scanf("%s %d %f %hd %c",username,&age,&salary,&code,&gender);

   printf("\n");
   printf("\nUsername: %s\nAge: %d\nSalary: %.2f\nCode: %d\nGender: %c\n",
            username,age,salary,code,gender);
}*/

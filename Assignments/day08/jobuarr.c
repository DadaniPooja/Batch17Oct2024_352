#include <stdio.h>

typedef union
{
   char name[32];
   unsigned short ucount;
   float salary;
   int workerNo;
   char *orgname;
}Job;

int main()
{
   Job uarr[10];
   uarr[0].salary=53.200;
   uarr[0].workerNo=101;
   uarr[1].salary=67.03;
   uarr[1].workerNo=102;

   printf("Salary: %f\n",uarr[0].salary);
   printf("WorkerNo: %d\n",uarr[0].workerNo);
   printf("Salary: %f\n",uarr[1].salary);
   printf("WorkerNo: %d\n",uarr[1].workerNo);
   return 0;
}

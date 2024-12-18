#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])   //pooja
{
  int n1=argv[2];
  int n2=argv[3];
  int res;
  if(strcmp(argv[1], "add") == 0) {
        res = n1 + n2;
        printf("Result: %d + %d = %d\n", n1, n2, res);
    } else if (strcmp(argv[1], "sub") == 0) {
        res = n1 - n2;
        printf("Result: %d - %d = %d\n", n1, n2, res);
    } else if (strcmp(argv[1], "mul") == 0) {
        res = n1 * n2;
        printf("Result: %d * %d = %d\n", n1, n2, res);
    } else if (strcmp(argv[1], "div") == 0) {
        if (n2 == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        result = operand1 / operand2;
        printf("Result: %.2f / %.2f = %.2f\n", operand1, operand2, result);
    } else {
        printf("Error: Invalid operation. Use 'add', 'sub', 'mul', or 'div'.\n");
        return 1;
    }
  return 0;
}


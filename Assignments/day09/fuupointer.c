#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main() {
    char operator;
    int x, y, result;

    int (*operations[4])(int, int) = {add, sub, multiply, divide};
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter first operand: ");
    scanf("%d", &x);
    printf("Enter second operand: ");
    scanf("%d", &y);

    int operation_index;
    switch (operator) {
        case '+':
            operation_index = 0;
            break;
        case '-':
            operation_index = 1;
            break;
        case '*':
            operation_index = 2;
            break;
        case '/':
            operation_index = 3;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    result = operations[operation_index](x, y);

    printf("Result: %d\n", result);

    return 0;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

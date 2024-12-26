#include <stdio.h>

int main() {
    float num1, num2, result;
    char opt;

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &opt); 

    if (opt == '+') {
        result = num1 + num2;
        printf("Result: %.2f\n", result);
    } 
    else if (opt == '-') {
        result = num1 - num2;
        printf("Result: %.2f\n", result);
    } 
    else if (opt == '*') {
        result = num1 * num2;
        printf("Result: %.2f\n", result);
    } 
    else if (opt == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            printf("Result: %.2f\n", result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } 
    else {
        printf("Error: Invalid operator.\n");
    }

    return 0;
}
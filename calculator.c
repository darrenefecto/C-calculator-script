#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    double num1, num2, result;
    char operation;
    int i, j;

    while (1) {
        printf("Enter calculation (e.g. 1+2-3*4/5): ");
        scanf_s("%s", input);

        num1 = 0;
        num2 = 0;
        result = 0;
        operation = '+';

        for (i = 0; i < strlen(input); i++) {
            if (isdigit(input[i])) {
                if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
                    num1 = num1 * 10 + (input[i] - '0');
                }
                else {
                    num2 = num2 * 10 + (input[i] - '0');
                }
            }
            else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                if (operation == '+') {
                    result += num1;
                }
                else if (operation == '-') {
                    result -= num1;
                }
                else if (operation == '*') {
                    result *= num1;
                }
                else if (operation == '/') {
                    if (num1 == 0) {
                        printf("Cannot divide by zero.\n");
                        goto end;
                    }
                    else {
                        result /= num1;
                    }
                }
                num1 = num2;
                num2 = 0;
                operation = input[i];
            }
        }
        if (operation == '+') {
            result += num1;
        }
        else if (operation == '-') {
            result -= num1;
        }
        else if (operation == '*') {
            result *= num1;
        }
        else if (operation == '/') {
            if (num1 == 0) {
                printf("Cannot divide by zero.\n");
                goto end;
            }
            else {
                result /= num1;
            }
        }
        printf("Result: %.2lf\n", result);
        end:;
    }

    return 0;
}

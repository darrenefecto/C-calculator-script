#include <stdio.h>
#include <string.h>
#include <ctype.h>

double evaluate(char* input, int start, int end) {
    double num = 0, result = 0;
    char operation = '+';

    for (int i = start; i < end; i++) {
        if (input[i] == ' ' || isspace(input[i])) {
            continue; // skip whitespace characters
        }
        if (input[i] == '(') {
            int j = i + 1, depth = 1;
            while (depth > 0 && j < end) {
                if (input[j] == '(') depth++;
                else if (input[j] == ')') depth--;
                j++;
            }
            double subresult = evaluate(input, i + 1, j - 1);
            if (operation == '*') {
                result *= subresult;
            }
            else if (operation == '/') {
                if (subresult == 0) {
                    printf("Cannot divide by zero.\n");
                    return 0;
                }
                result /= subresult;
            }
            else if (operation == '+') {
                result += subresult;
            }
            else if (operation == '-') {
                result -= subresult;
            }
            i = j - 1;
            num = 0;
        }
        else if (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
        }
        else {
            if (operation == '*') {
                result *= num;
            }
            else if (operation == '/') {
                if (num == 0) {
                    printf("Cannot divide by zero.\n");
                    return 0;
                }
                result /= num;
            }
            else if (operation == '+') {
                result += num;
            }
            else if (operation == '-') {
                result -= num;
            }

            operation = input[i];
            num = 0;
        }
    }

    if (operation == '*') {
        result *= num;
    }
    else if (operation == '/') {
        if (num == 0) {
            printf("Cannot divide by zero.\n");
            return 0;
        }
        result /= num;
    }
    else if (operation == '+') {
        result += num;
    }
    else if (operation == '-') {
        result -= num;
    }

    return result;
}

void calc() {
    char input[100];

    printf("Enter calculation (e.g. 1+2-3*4/5): ");
    fgets(input, sizeof(input), stdin); // read input using fgets

    double result = evaluate(input, 0, strlen(input));
    printf("Result: %.2lf\n", result);
}

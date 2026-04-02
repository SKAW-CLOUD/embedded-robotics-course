#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    printf("Simple Calculator (enter 'q' to quit)\n");

    while (1) {
        printf("\nEnter calculation (number operator number): ");

        // Read input; first check if user wants to quit
        if (scanf(" %c", &op) != 1) {
            printf("Error reading input.\n");
            break;
        }

        // Check for quit
        if (op == 'q' || op == 'Q') {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // Read the first number and the second number
        if (scanf("%lf %lf", &num1, &num2) != 2) {
            printf("Invalid input format. Use: number operator number\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (op) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Error: Unknown operator\n");
        }

        // Clear input buffer for next iteration
        while (getchar() != '\n');
    }

    return 0;
}

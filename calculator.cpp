#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Simple Calculator (type a non-number to quit)\n";

    while (true) {
        cout << "\nEnter calculation (number operator number): ";


        if (!(cin >> num1 >> op >> num2)) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        switch (op) {
            case '+':
                result = num1 + num2;
                cout << fixed << setprecision(2) << "Result: " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << fixed << setprecision(2) << "Result: " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << fixed << setprecision(2) << "Result: " << result << endl;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero" << endl;
                } else {
                    result = num1 / num2;
                    cout << fixed << setprecision(2) << "Result: " << result << endl;
                }
                break;
            default:
                cout << "Error: Unknown operator" << endl;
        }
    }

    return 0;
}

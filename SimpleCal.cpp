#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void displayMenu();
double getNumber(const string& prompt);
void performOperation(int choice);

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }
        if (choice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }
        performOperation(choice);
    }
    return 0;
}

void displayMenu() {
    cout << "\n=================================================" << endl;
    cout << "   SimpleCalc : Your Basic Arithmetic Companion" << endl;
    cout << "=================================================" << endl;
    cout << "Please select an operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
}

double getNumber(const string& prompt) {
    double number;
    cout << prompt;
    while (!(cin >> number)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number: ";
    }
    return number;
}

void performOperation(int choice) {
    double num1 = getNumber("Enter the first number: ");
    double num2 = getNumber("Enter the second number: ");
    double result;
    cout << fixed << setprecision(2);
    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "The Sum of "<<num1<<" and "<<num2<< " is: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "The Difference of "<<num1<<" and "<<num2<< " is: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "The Product of "<<num1<<" and "<<num2<< " is: " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "The Division of "<<num1<<" and "<<num2<< " is: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}
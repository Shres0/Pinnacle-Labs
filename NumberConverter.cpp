#include <iostream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int num) {
    string result = "";
    while (num > 0) {
        result = (num % 2 == 0 ? "0" : "1") + result;
        num /= 2;
    }
    return result == "" ? "0" : result;
}

// Function to convert decimal to octal
string decimalToOctal(int num) {
    string result = "";
    while (num > 0) {
        result = to_string(num % 8) + result;
        num /= 8;
    }
    return result == "" ? "0" : result;
}

// Function to convert decimal to hexadecimal
string decimalToHex(int num) {
    stringstream ss;
    ss << hex << uppercase << num;
    return ss.str();
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    int length = binary.size();
    for (int i = length - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to convert octal to decimal
int octalToDecimal(string octal) {
    int decimal = 0;
    int base = 1;
    int length = octal.size();
    for (int i = length - 1; i >= 0; --i) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }
    return decimal;
}

// Function to convert hexadecimal to decimal
int hexToDecimal(string hex) {
    int decimal = 0;
    int base = 1;
    int length = hex.size();
    for (int i = length - 1; i >= 0; --i) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * base;
        } else if (c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}

// Function to detect and validate user input
int detectAndValidateInput(string& input, int& base) {
    // Binary check
    if (regex_match(input, regex("^0b[01]+$"))) {
        base = 2;
        return binaryToDecimal(input.substr(2)); // Strip "0b"
    }
    // Octal check
    else if (regex_match(input, regex("^0o[0-7]+$"))) {
        base = 8;
        return octalToDecimal(input.substr(2)); // Strip "0o"
    }
    // Hexadecimal check
    else if (regex_match(input, regex("^0x[0-9A-Fa-f]+$"))) {
        base = 16;
        return hexToDecimal(input.substr(2)); // Strip "0x"
    }
    // Decimal check
    else if (regex_match(input, regex("^[0-9]+$"))) {
        base = 10;
        return stoi(input); // Convert directly
    }
    // Invalid input
    else {
        cout << "Invalid input format!" << endl;
        return -1;
    }
}

// Function to display conversion options and perform the conversion
void performConversion(int decimalValue, int inputBase) {
    int outputBase;
    cout << "Choose the base to convert to (2 for Binary, 8 for Octal, 10 for Decimal, 16 for Hexadecimal): ";
    cin >> outputBase;

    switch (outputBase) {
        case 2:
            cout << "Binary: " << decimalToBinary(decimalValue) << endl;
            break;
        case 8:
            cout << "Octal: " << decimalToOctal(decimalValue) << endl;
            break;
        case 10:
            cout << "Decimal: " << decimalValue << endl;
            break;
        case 16:
            cout << "Hexadecimal: " << decimalToHex(decimalValue) << endl;
            break;
        default:
            cout << "Invalid output base choice!" << endl;
    }
}

int main() {
    string input;
    int decimalValue, base;

    while (true) {
        // Prompt user to enter a number
        cout << "Enter a value (use 0b for binary, 0o for octal, 0x for hexadecimal, or a decimal number): ";
        cin >> input;

        // Validate the input and convert it to decimal
        decimalValue = detectAndValidateInput(input, base);

        // If input was valid, proceed with conversion
        if (decimalValue != -1) {
            performConversion(decimalValue, base);
        }
    }

    return 0;
}
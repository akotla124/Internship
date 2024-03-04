#include <iostream>
int main() {
    char operation;
    double num1, num2, result;
    std::cout << "Welcome to the Simple Calculator!" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;
    switch(operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            } else {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation entered." << std::endl;
    }
    return 0;
}


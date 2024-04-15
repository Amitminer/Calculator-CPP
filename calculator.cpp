#include <iostream>
#include <functional>
#include <map>

using namespace std;

template <typename Values>
class Calculator {
private:
    Values num1, num2;

public:
    Calculator(Values n1, Values n2) : num1(n1), num2(n2) {}

    Values add() {
        return num1 + num2;
    }

    Values subtract() {
        return num1 - num2;
    }

    Values multiply() {
        return num1 * num2;
    }

    Values divide() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error! Division by zero!\n";
            return 0; // Return 0 as an error indicator
        }
    }
};

void getCalculatorInput(float& num1, float& num2, int& operation) {
    cout << "Select operation:\n"
         << "1. Add\n"
         << "2. Subtract\n"
         << "3. Multiply\n"
         << "4. Divide\n"
         << "Enter your choice (1-4): ";
    cin >> operation;
    
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;
}


int main() {
    float num1, num2;
    int operation;

    getCalculatorInput(num1, num2, operation);

    Calculator<float> calc(num1, num2);

    // Map operation numbers to member function pointers
    map<int, function<float()>> operations = {
    {1, [&calc]() { return calc.add(); }},
    {2, [&calc]() { return calc.subtract(); }},
    {3, [&calc]() { return calc.multiply(); }},
    {4, [&calc]() { return calc.divide(); }}
};

    auto it = operations.find(operation);
    if (it != operations.end()) {
        cout << "Result: " << it->second() << '\n';
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

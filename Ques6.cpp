#include <iostream>

using namespace std;


int factorial(int n) {

    if (n == 0 || n == 1) {
        return 1;
    }

    int fact = 1;

    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }

    return fact;
}

int main() {
    int num;
    cout << "Enter a number to find its factorial: ";
    cin >> num;


    int result = factorial(num);


    cout << "Factorial of " << num << " is: " << result << endl;

    return 0;
}


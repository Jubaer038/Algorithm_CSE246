#include <iostream>

using namespace std;

class SquareRootCalculator {
public:
    double calculateSquareRoot(double number, int precision) {
        double start = 0.0;
        double end = number;
        double increment = 1.0 / getPow(10, precision);
        double mid, ans;

        while (start <= end) {
            mid = (start + end) / 2;
            if (mid * mid == number) {
                ans = mid;
                break;
            }
            if (mid * mid < number) {
                start = mid + increment;
                ans = mid;
            } else {
                end = mid - increment;
            }
        }

        double incrementPrecision = 0.1;
        for (int i = 0; i < precision; i++) {
            while (ans * ans <= number) {
                ans += incrementPrecision;
            }
            ans -= incrementPrecision;
            incrementPrecision /= 10;
        }

        return ans;
    }

private:
    double getPow(double base, int exponent) {
        double result = 1.0;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
};

int main() {
    double number;
    int precision;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the precision: ";
    cin >> precision;

    SquareRootCalculator calculator;
    double result = calculator.calculateSquareRoot(number, precision);

    cout << "Square root: " << result << endl;

    return 0;
}

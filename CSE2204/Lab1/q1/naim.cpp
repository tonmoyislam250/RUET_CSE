#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double evaluate(double coeffs[], int deg, double x)
{
    double res = 0;
    for (int i = deg; i >= 0; i--)
        res += coeffs[i] * pow(x, i);
    return res;
}

void bisection(double coeffs[], int deg, double a, double b)
{
    double tol = 1e-4;
    int maxIter = 100;
    if (evaluate(coeffs, deg, a) * evaluate(coeffs, deg, b) > 0)
    {
        cout << "Cannot apply bisection method to this interval." << endl;
        return;
    }
    cout << "Bisection Method:" << endl
         << setw(5) << "Step" << setw(12) << "a" << setw(12) << "b" << setw(12) << "x" << setw(12) << "f(x)" << setw(12) << "Error" << endl;
    for (int step = 1; step <= maxIter; step++)
    {
        double x = (a + b) / 2, fx = evaluate(coeffs, deg, x), prev;
        cout << setw(5) << step << setw(12) << a << setw(12) << b << setw(12) << x << setw(12) << fx << setw(12) << abs(x - prev) << endl;
        if (abs(x - prev) < tol)
        {
            cout << "Root found: " << setprecision(5) << x << endl;
            return;
        }
        prev = x;
        if (fx * evaluate(coeffs, deg, a) < 0)
            b = x;
        else
            a = x;
    }
    cout << "Maximum iterations reached. No root found within the specified tolerance." << endl;
}

void falsePosition(double coeffs[], int deg, double a, double b)
{
    double tol = 1e-4;
    int maxIter = 100;
    if (evaluate(coeffs, deg, a) * evaluate(coeffs, deg, b) > 0)
    {
        cout << "Cannot apply false position method to this interval." << endl;
        return;
    }
    cout << "False Position Method:" << endl
         << setw(5) << "Step" << setw(12) << "a" << setw(12) << "b" << setw(12) << "x" << setw(12) << "f(x)" << setw(12) << "Error" << endl;
    for (int step = 1; step <= maxIter; step++)
    {
        double fa = evaluate(coeffs, deg, a), fb = evaluate(coeffs, deg, b), prev;
        double x = (a * fb - b * fa) / (fb - fa);
        double fx = evaluate(coeffs, deg, x);
        cout << setw(5) << step << setw(12) << a << setw(12) << b << setw(12) << x << setw(12) << fx << setw(12) << abs(x - prev) << endl;
        if (abs(x - prev) < tol)
        {
            cout << "Root found: " << setprecision(5) << x << endl;
            return;
        }
        prev = x;
        if (fa * fx < 0)
            b = x;
        else
            a = x;
    }
    cout << "Maximum iterations reached. No root found within the specified tolerance." << endl;
}
int main()
{
    int deg;
    double a, b;
    cout << "Enter degree of the polynomial: ";
    cin >> deg;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    double c[deg + 1];
    cout << "Enter coefficients from highest to lowest degree: ";
    for (int i = deg; i >= 0; i--)
        cin >> c[i];
    bisection(c, deg, a, b);
    falsePosition(c, deg, a, b);
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x * x * x - 2 * x - 5;
}
double df(double x)
{
    return 3 * x * x - 2;
}
double iterationMethod(double initialGuess, double errorThreshold)
{
    double x = initialGuess;
    double prev_x;
    double error;
    int i = 0;
    do
    {
        prev_x = x;
        x = x - 0.1 * f(x);
        error = abs(x - prev_x);
        std::cout << "Iteration " << i + 1 << ": " << x << ", Error: " << error << std::endl;
        i++;
    } while (error > errorThreshold);
    cout << "\nRoot is-  " << x << endl;
    return x;
}
double newtonRaphsonMethod(double initialGuess, double errorThreshold)
{
    double x = initialGuess;
    double prev_x;
    double error;
    int i = 0;
    do
    {
        prev_x = x;
        x = x - f(x) / df(x);
        error = abs(x - prev_x);
        std::cout << "Iteration " << i + 1 << ": " << x << ", Error: " << error << std::endl;
        i++;
    } while (error > errorThreshold);
    cout << "\nRoot is-  " << x << endl;
    return x;
}
int main()
{
    double initialGuess = 1.8;
    double errorThreshold;
    cout << "Enter the error threshold: ";
    cin >> errorThreshold;
    std::cout << "Iteration Method Results: " << std::endl;
    iterationMethod(initialGuess, errorThreshold);
    std::cout << std::endl;
    cout << "Newton-Raphson Method Results: " << std::endl;
    newtonRaphsonMethod(initialGuess, errorThreshold);
    return 0;
}

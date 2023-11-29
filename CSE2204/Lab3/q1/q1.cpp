#include <iostream>
#include <windows.h>
using namespace std;
double calculateCombination(double n, double r, bool h)
{
    double result = 1;
    for (int i = 1; i <= r; ++i)
    {
        if (h == true)
            result *= (n - i + 1) / i;
        else if (h == false)
            result *= (n + i - 1) / i;
    }
    return result;
}

void NewtonForward(double x, int n, double ys[], double xs[], double h)
{
    double sum = ys[0];
    cout << "x   ";
    for (int i = 0; i < n; i++)
        cout << xs[i] << " ";
    cout << endl;
    cout << "y   ";
    double ys1[n];
    for (int i = 0; i < n; i++)
    {
        ys1[i] = ys[i];
        cout << ys1[i] << " ";
    }

    cout << endl;
    for (int j = 0; j < n - 1; j++)
    {
        cout << "\u0394" << j + 1 << "y  ";
        for (int i = 0; i < n - (j + 1); i++)
        {
            cout << ys1[i + 1] - ys1[i] << " ";
            ys1[i] = ys1[i + 1] - ys1[i];
        }
        cout << endl;
        double p = (x - xs[0]) / h;
        sum += (calculateCombination(p, j + 1, true) * ys1[0]);
    }
    cout << "The Answer is: " << sum << endl;
}
void NewtonBackward(double x, int n, double ys[], double xs[], double h)
{
    double sum = ys[n - 1];
    cout << "x    ";
    for (int i = n - 1; i >= 0; i--)
        cout << xs[i] << " ";
    cout << endl;
    cout << "y    ";
    for (int i = n - 1; i >= 0; i--)
        cout << ys[i] << " ";
    cout << endl;
    for (int j = 0; j < n - 1; j++)
    {
        cout << "\u0394" << j + 1 << "y  ";
        for (int i = n - 2; i >= j; i--)
        {
            cout << ys[i + 1] - ys[i] << " ";
            ys[i + 1] = ys[i + 1] - ys[i];
        }
        cout << endl;
        double p = (x - xs[n - 1]) / h;
        // cout << p << endl;
        // cout << calculateCombination(p, j + 1, false) << " " << y[n - 1] << endl;
        sum += (calculateCombination(p, j + 1, false) * ys[n - 1]);
        // cout << sum << endl;
    }
    cout << "The Answer is: " << sum << endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout << "How many points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter x0 Values: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << "Enter y0 Values: ";
    for (int i = 0; i < n; i++)
        cin >> y[i];
    cout << "Enter x value: ";
    double x1;
    cin >> x1;
    double h = x[1] - x[0];
    while (1)
    {
        cout << "InterPolation\n1. Newton's Forward\n2. Newton's Backward\nplease choose:" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            NewtonForward(x1, n, y, x, h);
            break;
        case 2:
            NewtonBackward(x1, n, y, x, h);
            break;
        }
    }
}
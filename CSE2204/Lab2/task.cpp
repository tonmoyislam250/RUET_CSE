#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double arr[100];
long double polynom2(long double x, int d, int h)
{
    long double sum = 0;

    if (h == 0 || h == 2)
    {
        for (int i = (d - 2); i >= -1; i--)
            sum += (arr[i + 1] * pow(x, i));
    }
    else if (h == 1)
    {
        for (int i = d; i >= 0; i--)
            sum += (arr[i] * pow(x, i));
    }
    if (h == 0)
        return sqrt(-sum);
    else if (h == 1)
        return (x - (sum / ((3 * pow(x, 2)) - 2)));
    else if (h == 2)
        return round(abs(-2.5 * pow(x, -2) * pow(-sum, -0.5)) * 10) / 10;
    return 0;
}
void method(int de, long double a, long double b, int h)
{
    int i = 1;
    long double prev = a, chk, err, k = polynom2(b, de, 2);
    long double e = (h == 0) ? ((1 - k) / k) * 0.0001 : 0.0001;
    (h == 0) ? cout << "Iteration Method" << endl : cout << "Newton Raphson Method" << endl;
    cout << "step  "
         << "Xr   "
         << "error" << endl;
    while (i > 0)
    {
        chk = polynom2(prev, de, h);
        err = (chk - prev);
        prev = chk;
        cout << i << "   " << chk << "   " << abs(err) << endl;
        if (abs(err) < e)
            break;
        i++;
    }

    cout << setprecision(5) << "ANSWER : " << prev << endl;
}
int main()
{
    long double a, b;
    int deg;
    int h;
    cout << "degree, a, b value : ";
    cin >> deg >> a >> b;
    cout << "What method do you want: (0 for Iteration 1 for Newton Raphson) ";
    cin >> h;
    cout << "Give the " << deg + 1 << " Coefficients: ";
    for (int i = deg; i >= 0; i--)
        cin >> arr[i];
    method(deg, a, b, h);
}
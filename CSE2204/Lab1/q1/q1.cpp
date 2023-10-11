#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double arr[100];
long double polynom(long double x, int d)
{
    long double sum = 0;
    for (int i = d; i >= 0; i--)
        sum += (arr[i] * pow(x, i));
    return sum;
}
void bisection(int de, long double a, long double b, bool h)
{
    int i = 1;
    long double temp1 = polynom(a, de), temp2 = polynom(b, de), mid = (h == true) ? ((a * temp2) - (b * temp1)) / (temp2 - temp1) : ((a + b) / 2);
    cout << "0"
         << " " << a << " " << b << " " << mid << " " << polynom(mid, de) << " " << mid << endl;
    if (temp1 * temp2 < 0)
    {
        while (i > 0)
        {
            long double prev = 0;
            long double chk = polynom(mid, de);
            prev = mid;
            if (temp1 * chk < 0)
                b = mid;
            else if (temp1 * chk == 0)
                break;
            else if (temp1 * chk > 0)
                a = mid;
            temp1 = polynom(a, de);
            temp2 = polynom(b, de);
            mid = (h == true) ? ((a * temp2) - (b * temp1)) / (temp2 - temp1) : ((a + b) / 2);
            long double err = (mid - prev);
            cout << i << " " << a << " " << b << " " << mid << " " << chk << " " << abs(err) << endl;
            if (abs(err) < 0.0001)
                break;
            i++;
        }
    }
    cout << "ANSWER : " << setprecision(5) << mid << endl;
}
int main()
{
    long double a, b;
    int deg;
    cin >> deg >> a >> b;
    for (int i = deg; i >= 0; i--)
        cin >> arr[i];
    bisection(deg, a, b, false);
}
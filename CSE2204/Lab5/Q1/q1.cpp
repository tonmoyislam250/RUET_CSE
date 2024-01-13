#include <iostream>
using namespace std;

double funk(double x)
{
    return 1 / (1 + x);
}

double integration(double h, int y, int a, int b)
{
    double n = ((b - a) / h), x = a, sum = funk(x);
    for (int i = 1; i <= n; i++)
    {
        if (y == 1)
        {
            x = x + h;
            sum += 2 * funk(x);
        }
        else if (y == 2)
        {
            if (i % 2 == 0)
            {
                x = x + h;
                sum += 2 * funk(x);
            }
            else if (i % 2 != 0)
            {
                x = x + h;
                sum += 4 * funk(x);
            }
        }
        else if (y == 3)
        {
            if (i % 3 == 0)
            {
                x = x + h;
                sum += 2 * funk(x);
            }
            else if (i % 3 != 0)
            {
                x = x + h;
                sum += 3 * funk(x);
            }
        }
    }
    if (y == 1)
        sum = (h / 2) * (sum + funk(x + n));
    else if (y == 2)
        sum = (h / 3) * (sum + funk(x + n));
    else if (y == 3)
        sum = (3 * h / 8) * (sum + funk(x + n));
    return sum;
}
int main()
{
    double h, a, b;
    cout << "enter the interval, LL, HL: ";
    cin >> h >> a >> b;
    double re = integration(h, 1, a, b);
    cout << "The area value of 1/(1+x) by trapizoidal is = " << re << endl;
    re = integration(h, 2, a, b);
    cout << "The area value of 1/(1+x) by simpson's 1/3 rule is = " << re << endl;
    re = integration(h, 3, a, b);
    cout << "The area value of 1/(1+x) by simpson's 3/8 rule is = " << re << endl;
}
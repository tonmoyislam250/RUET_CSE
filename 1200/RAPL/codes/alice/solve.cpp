#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int t;
    double a, b, c;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cin >> a >> b >> c;
        double x, y, i;
        i = (2 * c) / a;
        x = sqrt(pow(a, 2) + pow(b, 2));
        y = sqrt(pow(i - a, 2) + pow(b, 2));
        // cout << fixed << setprecision(15) << x << endl;
        double re = 0;
        re = (x * y * i) / (2 * c);
        cout << fixed << setprecision(15) << "Case " << j << ": " << re << endl;
    }
}
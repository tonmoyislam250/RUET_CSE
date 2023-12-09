#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double x[n], y[n], sumx = 0, sumy = 0;
    double avg1 = 0, avg2 = 0, a = 0, b = 0, c = 0, sq1 = 0;
    cout << "xi "
         << "xi2\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sumx += x[i];
        sq1 += pow(x[i], 2);
        cout << x[i] << " " << pow(x[i], 2) << endl;
    }
    cout << "yi "
         << "xiyi\n";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
        sumy += y[i];
        a += (x[i] * y[i]);
        cout << y[i] << " " << (x[i] * y[i]) << endl;
    }
    avg1 = sumx / n;
    avg2 = sumy / n;
    double a1 = ((n * a) - (sumx * sumy)) / ((n * sq1) - pow(sumx, 2));
    double a0 = avg2 - (a1 * avg1);
    cout << "m = " << a1 << " c = " << a0 << endl;
}
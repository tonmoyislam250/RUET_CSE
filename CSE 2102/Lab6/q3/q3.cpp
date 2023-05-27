#include <iostream>
using namespace std;

int extend(int a, int b, int &x, int &y)
{
    cout << "a: " << a << " b: " << b << endl;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extend(b, a % b, x1, y1);
    cout << "x1: " << x1 << " y1: " << y1 << endl;
    x = y1;
    y = x1 - y1 * (a / b);
    cout << "x: " << x << " y: " << y << endl;
    return d;
}
int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int g = extend(a, b, x, y);
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << endl;
}
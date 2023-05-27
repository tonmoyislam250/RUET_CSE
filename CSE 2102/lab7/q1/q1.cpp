#include <iostream>
using namespace std;
int extend(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extend(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    int n, MM = 1;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
            if (j == 1)
            {
                cout << "a[i][j]: " << a[i][j] << endl;
                MM *= a[i][j];
            }
        }
    }
    cout << "MM: " << MM << endl; // "MM" stands for "M
    int M[n];
    for (int i = 0; i < n; i++)
        M[i] = MM / a[i][1];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        extend(M[i], a[i][1], x, y);
        sum += M[i] * x * a[i][0];
    }
    cout << sum << endl;
}
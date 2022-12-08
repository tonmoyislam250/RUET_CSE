#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
void solve()
{
    int a, b, t, ca, cb, cv;
    cin >> a >> b;
    cin >> t;
    int w = t;
    int i = 0;
    double r[t];
    while (t--)
    {
        cin >> ca >> cb >> cv;
        r[i] = sqrt(pow((ca - a), 2) + pow((cb - b), 2)) / cv;
        i++;
    }
    double min = r[0];
    for (int j = 0; j < w; j++)
    {
        // cout << r[j] << " ";
        if (r[j] < min)
            min = r[j];
    }
    printf("%.20f", min);
}
int main()
{
    solve();
}
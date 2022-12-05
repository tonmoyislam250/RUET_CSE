#include <iostream>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    int a[t][3];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            for (int j = 0; j < t; j++)
                sum1 = sum1 + a[j][i];
            break;
        case 1:
            for (int j = 0; j < t; j++)
                sum2 = sum2 + a[j][i];
            break;
        case 2:
            for (int j = 0; j < t; j++)
                sum3 = sum3 + a[j][i];
            break;
        }
    }
    // cout << sum1 << endl;
    if (sum1 == 0 && sum2 == 0 && sum3 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    solve();
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int max(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
void solve()
{
    int t;
    cin >> t;
    int sum = 0, temp = 0, result[t], r = 0;
    memset(result, 0, sizeof(result));
    int a[t][2];
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < t; i++)
    {
        temp = sum;
        sum = sum - a[i][0];
        sum = sum + a[i][1];
        // cout << sum << " ";
        if (sum > temp)
        {
            result[r] = sum;
            r++;
        }
    }
    // cout << endl;
    // for (int i = 0; i < t; i++)
    //     cout << result[i] << " ";
    // cout << endl;
    cout << max(result, t) << endl;
}
int main()
{
    solve();
}
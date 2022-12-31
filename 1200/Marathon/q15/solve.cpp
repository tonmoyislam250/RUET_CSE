#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    x[0] = a[0];
    for (int i = 1; i < n; i++)
        x[i] = __gcd(x[i - 1], a[i]);
    y[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        y[i] = __gcd(y[i + 1], a[i]);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = max(__gcd(x[i - 1], y[i + 1]), ans);
    }
    ans = max(ans, max(y[1], x[n - 2]));
    cout << ans << endl;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long m = n / 2;
    if (m & 1)
    {
        cout << "NO" << endl;
        return;
    }
    vector<long long> v(n);
    long long c = 2;
    for (long long i = 0; i < m; i++)
    {
        v[i] = c;
        c += 2;
    }
    c = 1;
    for (long long i = m; i < n - 1; i++)
    {
        v[i] = c;
        c += 2;
    }
    c += (m);
    v[n - 1] = c;
    cout << "YES" << endl;
    for (long long i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
        solve();
}

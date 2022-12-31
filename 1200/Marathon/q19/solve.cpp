#include <iostream>
#include <cstring>
using namespace std;
void solve()
{
    long long n, w;
    cin >> n >> w;
    long long a[n], jog[n];
    memset(a, n, 0);
    jog[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        jog[i] = a[i] + jog[i - 1];
    }
    while (w--)
    {
        int k, l;
        cin >> k >> l;
        cout << jog[l] - jog[k - 1] << endl;
    }
}
int main()
{
    solve();
}
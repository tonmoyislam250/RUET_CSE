#include <iostream>
using namespace std;
void solve()
{
    long long a, b, c, d;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        d = a + b + c - 1;
        cout << abs(d) << endl;
    }
}
int main()
{
    solve();
}
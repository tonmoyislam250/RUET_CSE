#include <iostream>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long b1 = 0, b2 = 0, j1 = 0, j2 = 0;
        int n, m;
        cin >> n;
        while (n--)
        {
            int temp;
            cin >> temp;
            if (temp % 2 == 0)
            {
                j1++;
            }
            else
            {
                b1++;
            }
        }
        cin >> m;
        while (m--)
        {
            int temp;
            cin >> temp;
            if (temp % 2 == 0)
            {
                j2++;
            }
            else
            {
                b2++;
            }
        }
        cout << ((j1 * j2) + (b1 * b2)) << endl;
    }
}
int main()
{
    solve();
}
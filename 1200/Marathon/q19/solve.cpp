#include <iostream>
using namespace std;
void solve()
{
    int n, w;
    cin >> n >> w;
    int a[n],jog[n];
    for (int i = 0; i <n; i++)
        cin >> a[i];
        jog[i]
    while (w--)
    {
        int k, l, sum = 0;
        cin >> k >> l;
        for (int i = k-1; i <= l-1; i++)
            sum += a[i];
        cout << sum << endl;
    }
}
int main()
{
    solve();
}
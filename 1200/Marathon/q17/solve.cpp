#include <iostream>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        string num;
        int div, i = 0, r = 0;
        cin >> num >> div;
        if (div < 0)
            div = abs(div);
        if (num[0] == '-')
            i = 1;
        while (i < num.size())
        {
            r = r * 10 + (num[i] - '0');
            r %= div;
            i++;
        }
        if (r == 0)
            cout << "Case " << j << ": divisible" << endl;
        else
            cout << "Case " << j << ": not divisible" << endl;
    }
}
int main()
{
    solve();
}
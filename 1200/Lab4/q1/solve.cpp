#include <iostream>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a = s.length();
        if (a > 10)
        {
            cout << s[0] << a - 2 << s[a - 1] << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
}
int main()
{
    solve();
}
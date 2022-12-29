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
        if (s.length() > 10)
            cout << s.at(0) << s.length() - 2 << s.at(s.length() - 1) << endl;
        else
            cout << s << endl;
    }
}
int main()
{
    solve();
}
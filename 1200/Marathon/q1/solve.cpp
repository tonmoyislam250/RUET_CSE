#include <iostream>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    (s[0] >= 97 && s[0] <= 122) ? s[0] -= 32 : s[0] += 0;
    cout << s << endl;
}
int main()
{
    solve();
}
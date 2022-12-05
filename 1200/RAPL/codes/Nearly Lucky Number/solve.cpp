#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void solve()
{
    char s[18];
    int i = 0, count = 0;
    cin >> s;
    while (s[i] != '\0')
    {
        if (s[i] == '4' || s[i] == '7')
        {
            count++;
        }
        i++;
    }
    // cout << count << endl;
    if (count == 4 || count == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    solve();
}
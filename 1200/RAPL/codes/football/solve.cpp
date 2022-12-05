#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void solve()
{
    int i = 0, count1 = 0, count2 = 0;
    char s[101];
    cin >> s;
    while (s[i] != '\0')
    {
        if (s[i] == '0')
        {
            if (count2 < 7)
                count2 = 0;
            count1++;
        }
        if (s[i] == '1')
        {
            if (count1 < 7)
                count1 = 0;
            count2++;
        }
        i++;
    }
    // cout << count1 << " " << count2 << endl;
    if (count1 >= 7 || count2 >= 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    solve();
}
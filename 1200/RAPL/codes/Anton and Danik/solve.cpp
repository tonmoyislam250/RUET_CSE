#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void solve()
{
    int i = 0, t;
    int count1 = 0, count2 = 0;
    cin >> t;
    char s[t + 1];
    cin >> s;
    while (s[i] != '\0')
    {
        if (s[i] == 'A')
            count1++;
        if (s[i] == 'D')
            count2++;
        i++;
    }
    // cout << count1 << " " << count2 << endl;
    if (count1 > count2)
    {
        cout << "Anton" << endl;
    }
    else if (count1 < count2)
    {
        cout << "Danik" << endl;
    }
    else
    {
        cout << "Friendship" << endl;
    }
}
int main()
{
    solve();
}
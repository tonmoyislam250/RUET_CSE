#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void solve()
{
    char s[101], i = 0, j = 0;
    cin >> s;
    int count1 = 0, count2 = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 97 && s[i] <= 122)
            count1++;
        if (s[i] >= 65 && s[i] <= 90)
            count2++;
        i++;
    }
    // cout << count1 << " " << count2 << endl;
    if (count1 < count2)
    {
        while (s[j] != '\0')
        {
            if (s[j] >= 97 && s[j] <= 122)
                s[j] -= 32;
            j++;
        }
    }
    else if (count1 > count2 || count1 == count2)
    {
        while (s[j] != '\0')
        {
            if (s[j] >= 65 && s[j] <= 90)
                s[j] += 32;
            j++;
        }
    }
    cout << s << endl;
}
int main()
{
    solve();
}
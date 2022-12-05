#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void swap(char *a, char *b)
{
    char *temp;
    temp = a;
    a = b;
    b = temp;
}
void solve()
{
    int x, t, i = 0;
    cin >> x >> t;
    t += 1;
    char s[x + 1];
    char r[x + 1];
    cin >> s;
    while (t--)
    {
        while (s[i] != '\0')
        {
            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                // cout << s[i] << " " << s[i + 1] << endl;
                swap(s[i], s[i + 1]);
                // cout << s[i] << " " << s[i + 1] << endl;
            }

            i += 2;
        }
    }
    cout << s << endl;
}
int main()
{
    solve();
}
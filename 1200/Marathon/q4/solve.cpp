#include <iostream>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1;
    int ans = 0;
    while (cin >> s2)
    {
        if (s2 == "END_OF_TEXT")
            break;
        for (int i = 0; i < s2.size(); i++)
            if (s2[i] >= 'A' && s2[i] <= 'Z')
                s2[i] += 'a' - 'A';
        if (s1 == s2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
void compute(string s, int *LPS);
int kmpfrequency(string s1, string s2, int *LPS)
{
    int a = s1.length(), b = s2.length(), i = 0, j = 0;
    LPS[b];
    int count = 0;
    compute(s2, LPS);
    while ((a - i) >= (b - j))
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        if (j == b)
        {
            count++;
            j = LPS[j - 1];
        }
        else if (s1[i] != s2[j])
        {
            if (j != 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    return count;
}
void compute(string s, int *LPS)
{
    int l = s.length(), j = 0, i = 1;
    LPS[0] = 0;
    while (i < l)
    {
        if (s[i] == s[j])
        {
            j++;
            LPS[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string n, m;
        cin >> n;
        cin >> m;
        int LPS[m.length()];
        cout << "Case " << i << ": " << kmpfrequency(n, m, LPS) << endl;
    }
}
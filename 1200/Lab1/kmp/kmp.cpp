/* for naive search complexity is O(ab)
for KMP its O(a+b)
 */
#include <iostream>
#include <cstring>
using namespace std;
void compute(char *s, int *LPS);
void kmpsearch(char *s1, char *s2, int *LPS)
{
    int a = strlen(s1), b = strlen(s2), i = 0, j = 0;
    LPS[b];
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
            cout << "Pattern Found at index at : " << i - j;
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
}
void compute(char *s, int *LPS)
{
    int l = strlen(s), j = 0, i = 1;
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
    for (int i = 0; i < l; i++)
        cout << LPS[i] << " ";
    cout << endl;
}
int main()
{
    char m[] = "ABABCABAB";
    char n[] = "ABABDABACDABABCABAB";
    int LPS[strlen(m)];
    kmpsearch(n, m, LPS);
}
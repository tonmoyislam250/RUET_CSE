#include <iostream>
using namespace std;
bool h = false;
int u = 0;
int fact(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

string nextcombo(string perm, int n)
{
    u++;
    int i = perm.size() - 1;
    while (perm[i] == ('0' + n - perm.size() + i + 1))
    {
        if (i == 0)
        {
            h = true;
            break;
        }
        i = i - 1;
    }
    if (h)
        return "shutdown";
    else
    {
        perm[i] = perm[i] + 1;
        for (int j = i + 1; j <= perm.size() - 1; j++)
            perm[j] = perm[i] + j - i;
        cout << perm << endl;
        return perm;
    }
}
int maxRe(string str)
{
    int maxDigit = -1;

    for (char c : str)
    {
        if (std::isdigit(c))
        {
            int digit = c - '0';
            if (digit > maxDigit)
                maxDigit = digit;
        }
    }
    return maxDigit;
}
int main()
{
    int n, m;
    string perm;
    cout << "N<space>R<space>Combination" << endl;
    cin >> n >> m >> perm;
    int mm = (fact(n) / (fact(m) * fact(n - m))) - 1;
    if (perm.size() == m && maxRe(perm) <= n && perm[m - 1] - '0' == maxRe(perm))
    {
        while (mm--)
        {
            perm = nextcombo(perm, n);
            if (perm == "shutdown")
                break;
        }
    }
    else
        cout << "invalid inputs" << endl;
    cout << "Next Lexicographical combinations total found : " << u << endl;
}
#include <iostream>
#include <cstring>
using namespace std;
bool h = false;
int u = 0;
void swap(int *a, int *b)
{
    int *t = a;
    *a = *b;
    *b = *t;
}
int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
string nextperm(string perm)
{
    u++;
    int j = perm.size() - 2;
    while (perm[j] > perm[j + 1])
    {
        if (j == 0)
        {
            h = true;
            break;
        }
        j = j - 1;
    }
    if (h)
        return "shut";
    else
    {
        int k = perm.size() - 1;
        while (perm[j] > perm[k])
            k = k - 1;
        swap(perm[j], perm[k]);
        int r = perm.size() - 1, s = j + 1;
        while (r > s)
        {
            swap(perm[r], perm[s]);
            r = r - 1;
            s = s + 1;
        }
        cout << perm << endl;
        return perm;
    }
}
int main()
{
    string perm;
    cout << "first permutation" << endl;
    cin >> perm;
    // cout << perm << endl;
    int t = factorial(perm.size());
    while (t--)
    {
        perm = nextperm(perm);
        if (perm == "shut")
            break;
    }
    cout << "total found : " << u - 1 << endl;
}
#include <iostream>
using namespace std;
int a[1000007], n;

int bs(int k)
{
    int l = 0, r = n, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (k == a[m])
            return 1;
        if (k > a[m])
            l = m + 1;
        else if (k < a[m])
            r = m;
    }
    return 0;
}

int main()
{
    int q, k, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        if (bs(k))
            c++;
    }
    cout << c << endl;
    return 0;
}
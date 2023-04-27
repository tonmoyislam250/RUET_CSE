#include <iostream>
#include <cstring>
using namespace std;
int last[1000], k = 0, r = 0;
int cop[1000];
void print(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        if (a[i] != 0)
            cout << a[i] << " ";
    }
}
void Union(int a[], int s)
{
    bool h = true;
    for (int i = 0; i < s; i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] == a[j])
                {
                    h = false;
                    break;
                }
                else
                    h = true;
            }
        }
        if (h)
        {
            last[k] = a[i];
            k++;
        }
    }
}
void removedup(int a[], int s)
{
    int i, j;
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < r; j++)
        {
            if (last[i] == cop[j])
                break;
        }

        if (j == r)
        {
            cop[r] = last[i];
            r++;
        }
    }
}
int main()
{
    int n, m;
    cout << "input size" << endl;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    Union(a, n);
    Union(b, m);
    removedup(last, n + m);
    print(cop, n + m);
}
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partioner(int a[], int x, int y)
{
    int p = a[y];
    cout << "Pivot : " << p << endl;
    int j = x, i = x - 1;
    // if (p!=a[y])
    // {

    // }
    while (j <= y - 1)
    {
        // if (a[j] == p)
        // {
        //     j++;
        //     continue;
        // }
        // else
        if (a[j] < p)
        {
            i++;
            swap(&a[i], &a[j]);
        }
        j++;
    }
    swap(&a[i + 1], &a[y]);
    return i + 1;
}
void qs(int m[], int size, int x, int y)
{
    if (x < y)
    {
        int h = partioner(m, x, y);
        for (int i = 0; i <= size - 1; i++)
        {
            if (i == h)
                cout << "(" << m[i] << ")";
            else
            {
                cout << m[i] << " ";
            }
        }
        // cout << "\t";
        // for (int i = h + 1; i <= y; i++)
        //     cout << a[i] << " ";
        cout
            << endl;
        qs(m, size, x, h - 1);
        qs(m, size, h + 1, y);
    }
}
int main()
{
    int a[] = {2, 5, 1, 7, 8, 3, 9, 4};
    int s = sizeof(a) / sizeof(a[0]);
    // cout << s << endl;
    cout << "Before Swap" << endl;
    for (int i : a)
        cout << i << " ";
    cout << endl;
    qs(a, s, 0, s - 1);
    cout << "After Swap" << endl;
    for (int i : a)
        cout << i << " ";
    cout << endl;
}
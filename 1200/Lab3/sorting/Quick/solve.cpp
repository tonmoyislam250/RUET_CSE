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
void qs(int a[], int x, int y)
{
    if (x < y)
    {
        int h = partioner(a, x, y);
        for (int i = 0; i <= 5; i++)
            cout << a[i] << " ";
        // cout << "\t";
        // for (int i = h + 1; i <= y; i++)
        //     cout << a[i] << " ";
        cout << endl;
        qs(a, x, h - 1);
        qs(a, h + 1, y);
    }
}
int main()
{
    int a[] = {7, 5, 1, 4, 3, 2};
    int s = sizeof(a) / sizeof(a[0]);
    cout << "Before Swap" << endl;
    for (int i : a)
        cout << i << " ";
    cout << endl;
    cout << "After Swap" << endl;
    qs(a, 0, s - 1);
    // for (int i : a)
    //     cout << i << " ";
    // cout << endl;
}
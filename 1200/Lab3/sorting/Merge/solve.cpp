#include <iostream>
using namespace std;
void merger(int a[], int x, int m, int y)
{
    int i = 0, j = 0;
    auto size1 = m - x + 1, size2 = y - m;
    int *b = new int[size1], *c = new int[size2];
    cout << "Low = " << x << " "
         << "Mid= " << m << " End = " << y << " Size1 = " << size1 << " Size2 = " << size2 << endl;
    while (i < size1)
    {
        b[i] = a[x + i];
        cout << b[i] << " ";
        i++;
    }
    while (j < size2)
    {
        c[j] = a[m + 1 + j];
        cout << c[j] << " ";
        j++;
    }
    cout << endl;
    auto ii = 0, jj = 0, kk = x;
    while (ii < size1 && jj < size2)
    {
        if (b[ii] <= c[jj])
        {
            a[kk] = b[ii];
            cout << b[ii] << " ";
            ii++;
        }
        else
        {
            a[kk] = c[jj];
            cout << c[jj] << " ";
            jj++;
        }
        kk++;
    }
    while (ii < size1)
    {
        a[kk] = b[ii];
        cout << b[ii] << " ";
        ii++;
        kk++;
    }
    while (jj < size2)
    {
        a[kk] = c[jj];
        cout << c[jj] << " ";
        jj++;
        kk++;
    }
    cout << endl;
}

void mergeSort(int a[], int x, int y)
{
    auto m = x + (y - x) / 2;
    if (x < y)
    {
        mergeSort(a, x, m);
        mergeSort(a, m + 1, y);
        merger(a, x, m, y);
    }
}
void print(int a[], int x, int y)
{
    for (auto i = x; i < y; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int a[] = {8, 4, 5, 1, 3, 2, 7};
    auto s = sizeof(a) / sizeof(a[0]);
    cout << "Before Sorting" << endl;
    print(a, 0, s);
    mergeSort(a, 0, s - 1);
    cout << "After Sorting" << endl;
    print(a, 0, s);
}
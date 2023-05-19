#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void merger(long long a[], long long x, long long m, long long y)
{
    long long i = 0, j = 0;
    auto size1 = m - x + 1, size2 = y - m;
    long long *b = new long long[size1], *c = new long long[size2];
    while (i < size1)
    {
        b[i] = a[x + i];
        i++;
    }
    while (j < size2)
    {
        c[j] = a[m + 1 + j];
        j++;
    }
    long long ii = 0, jj = 0, kk = x;
    while (ii < size1 && jj < size2)
    {
        if (b[ii] <= c[jj])
        {
            a[kk] = b[ii];
            ii++;
        }
        else
        {
            a[kk] = c[jj];
            jj++;
        }
        kk++;
    }
    while (ii < size1)
    {
        a[kk] = b[ii];
        ii++;
        kk++;
    }
    while (jj < size2)
    {
        a[kk] = c[jj];
        jj++;
        kk++;
    }
    delete[] b;
    delete[] c;
}

void mergeSort(long long a[], long long x, long long y)
{
    auto m = x + (y - x) / 2;
    if (x < y)
    {
        mergeSort(a, x, m);
        mergeSort(a, m + 1, y);
        merger(a, x, m, y);
    }
}
void printarray(long long arr[], long long size)
{
    long long i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}
void genFile(long long arr[], long long n)
{
    srand((unsigned)time(NULL));
#ifdef _WIN32
    system("del unsorteddata.txt");
#endif
#ifdef linux
    system("rm unsorteddata.txt");
#endif
    ofstream hello("unsorteddata.txt");
    for (long long i = 0; i < n; i++)
        hello << rand() % 100 << endl;
    hello.close();
    ifstream hi("unsorteddata.txt");
    for (int i = 0; i < n; i++)
        hi >> arr[i];
    // printarray(arr, n);
    hi.close();
}

int main()
{
    long long n, f, off;
    cin >> n >> f >> off;
    for (int i = 1; i <= f; i++)
    {
        long long arr[n];
        genFile(arr, n);
        clock_t t;
        t = clock();
        mergeSort(arr, 0, n - 1);
        // cout << endl;
        // printarray(arr, n);
        t = clock() - t;
        cout << "Time taken: " << float(t) / CLOCKS_PER_SEC << " seconds "
             << "for " << n << " Numbers" << endl;
        n += off;
    }
}
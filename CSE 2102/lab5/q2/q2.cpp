/*
g++ .\q2\q2.cpp -o .\q2\q2.exe -I C:\Users\Tonmo\AppData\Local\Programs\Python\Python310\include
-I include
-I C:\Users\Tonmo\AppData\Local\Programs\Python\Python310\Lib\site-packages\numpy\core\include
-L C:\Users\Tonmo\AppData\Local\Programs\Python\Python310\libs -lpython310
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;
void merger(long long a[], long long x, long long m, long long y)
{
    long long i = 0, j = 0;
    long long size1 = m - x + 1, size2 = y - m;
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
    long long m = x + (y - x) / 2;
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
    system("del unsorteddata.data");
#endif
#ifdef linux
    system("rm unsorteddata.data");
#endif
    ofstream hello("unsorteddata.data");
    for (long long i = 0; i < n; i++)
        hello << rand() % 1000 << endl;
    hello.close();
    ifstream hi("unsorteddata.data");
    for (long long i = 0; i < n; i++)
        hi >> arr[i];
    // printarray(arr, n);
    hi.close();
}

int main()
{
    long long n, f, off;
    cin >> n >> f >> off;
    std::vector<long long> x(f), y(f);
    for (int i = 0; i < f; i++)
    {
        long long *arr = new long long[n];
        genFile(arr, n);
        clock_t t;
        t = clock();
        mergeSort(arr, 0, n - 1);
        // cout << endl;
        // printarray(arr, n);
        t = clock() - t;
        cout << "Time taken: " << double(t) / CLOCKS_PER_SEC << " seconds "
             << "for " << n << " Numbers" << endl;
        x.at(i) = n;
        y.at(i) = t;
        n += off;
    }
    plt::figure_size(1920, 1080);
    plt::plot(x, y);
    plt::title("Merge Sort Time Complexity Analysis O(nlogn)");
    plt::show();
}
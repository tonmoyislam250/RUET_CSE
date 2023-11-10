#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
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
int main()
{
    srand(time(0));
    long long n, target, max, min;
    cout << "How many Numbers : ";
    cin >> n;
    long long arr[n];
    string file = "../inputs/search" + to_string(n) + ".txt";
    ifstream input(file);
    for (long long i = 0; i < n; i++)
        input >> arr[i];
    input.close();
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "MergeSort Method" << endl;
    cout << "Run time: " << duration.count() << " microseconds" << endl;
}
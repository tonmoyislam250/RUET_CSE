#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
void swap(long long *a, long long *b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}
long long partioner(long long a[], long long x, long long y)
{
    long long p = a[y];
    // cout << "Pivot : " << p << endl;
    long long j = x, i = x - 1;
    while (j <= y - 1)
    {
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
void qs(long long m[], long long size, long long x, long long y)
{
    if (x < y)
    {
        long long h = partioner(m, x, y);
        qs(m, size, x, h - 1);
        qs(m, size, h + 1, y);
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
    qs(arr, n, 0, n - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "QuickSort Method" << endl;
    cout << "Run time: " << duration.count() << " microseconds" << endl;
}
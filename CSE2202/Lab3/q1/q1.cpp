#include <bits/stdc++.h>
using namespace std;

void maxmin_brut(long long size)
{
    long long arr[size];
    string file = "../inputs/search" + to_string(size) + ".txt";
    ifstream input(file);
    for (long long i = 0; i < size; i++)
        input >> arr[i];
    input.close();
    long long max = arr[1], min = arr[1];
    auto start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "BruteForce Method" << endl;
    std::cout << "Run time: " << duration.count() << " microseconds" << std::endl;
    cout << "Max : " << max << endl;
    cout << "Min : " << min << endl;
}
void MaxMin(long long arr[], long long i, long long j, long long &max, long long &min)
{
    if (i == j)
        max = min = arr[i];
    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            max = arr[j];
            min = arr[i];
        }
        else
        {
            max = arr[i];
            min = arr[j];
        }
    }
    else
    {
        long long mid = (i + j) / 2;
        long long maxl, minl;
        MaxMin(arr, i, mid, max, min);
        MaxMin(arr, mid + 1, j, maxl, minl);
        if (max < maxl)
            max = maxl;
        if (min > minl)
            min = minl;
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
    maxmin_brut(n);
    auto start = std::chrono::high_resolution_clock::now();
    MaxMin(arr, 0, n - 1, max, min);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Recursive Method" << endl;
    std::cout << "Run time: " << duration.count() << " microseconds" << std::endl;
    cout << "Max : " << max << endl;
    cout << "Min : " << min << endl;
}
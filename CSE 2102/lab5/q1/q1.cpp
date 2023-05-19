#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void swap(long long *x, long long *y)
{
    long long temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(long long arr[], long long n)
{
    long long i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
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
        bubbleSort(arr, n);
        t = clock() - t;
        cout << "Time taken: " << float(t) / CLOCKS_PER_SEC << " seconds "
             << "for " << n << " Numbers" << endl;
        n += off;
    }
}
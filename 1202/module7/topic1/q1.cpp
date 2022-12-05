#include <iostream>
using namespace std;
void insertion(int a[], int n)
{
    int i = 1, j, k;
    while (i < n)
    {
        k = a[i];
        j = i - 1;
        cout << "\nkey = " << k << endl;
        // cout << k << " ";
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            // cout << a[j] << " ";
            j--;
        }
        a[j + 1] = k;
        i++;
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter your array size : ";
    cin >> n;
    int a[n];
    cout << "Enter your array elements = ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Before Sorting " << endl;
    print(a, n);
    insertion(a, n);
    cout << "After Sorting" << endl;
    print(a, n);
}
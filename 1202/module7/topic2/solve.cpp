#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j, min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        cout << "min = " << a[min] << " "
             << "swap position = " << i << endl;
        if (min != i)
            swap(&a[min], &a[i]);
        cout << "min = " << a[min] << " "
             << "swap position = " << i << endl;
        cout << "_________________" << endl;
    }
}
int main()
{
    int i = 0, n = 5;
    int a[n];
    cout << "Enter your values : ";
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
    cout << "Before sorting" << endl;
    display(a, n);
    selection(a, n);
    cout << "After Sorting" << endl;
    display(a, n);
}
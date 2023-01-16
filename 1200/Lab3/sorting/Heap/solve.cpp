//heapsort
#include <iostream>
using namespace std;
void display(int c[], int n)
{
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void createheap(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int c = i;
        do
        {
            int r = (c - 1) / 2;
            if (a[r] < a[c])
            {
                swap(a[r], a[c]);
            }
            c = r;
        } while (c != 0);
    }
}
void deleteheap(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[i], &a[0]);
        //cout << a[0] << " " << a[i] << endl;
        int r = 0, c;
        do
        {
            c = (2 * r + 1);
            if (a[c] < a[c + 1] && c < i - 1)
                c = c + 1;
            if (a[r] < a[c] && c < i)
            {
                //cout << r << endl;
                swap(&a[r], &a[c]);
                //cout << a[r] << " " << a[c] << endl;
            }
            r = c;
        } while (c < i);
        //display(a, i);
    }
}
int main()
{
    int b[] = {10, 20, 15, 17, 9, 21};
    int s = sizeof(b) / sizeof(b[0]);
    cout << "Unsorted Array = ";
    display(b, s);
    createheap(b, s);
    cout << "Max Heap = ";
    display(b, s);
    deleteheap(b, s);
    cout<<"Sorted Array = ";
    display(b, s);
}

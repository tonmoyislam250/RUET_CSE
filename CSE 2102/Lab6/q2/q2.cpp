#include <iostream>
using namespace std;
#define MAX 1000001
void makespf(int a[], int n)
{
    a[1] = 1;
    int ii = 0;
    int b[n];
    for (int i = 2, j = 4; i < MAX, j < MAX; i++, j += 4)
    {
        a[i] = i;
        if (a[i] != i)
            a[j] = 2;
    }

    for (int i = 3; i * i < MAX; i++)
    {
        if (a[i] == i)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                if (a[j] == j)
                    a[j] = i;
            }
        }
    }
    while (n != 1)
    {
        b[ii] = a[n];
        ii++;
        n = n / a[n];
    }
    for (int i = 0; i < ii; i++)
    {
        if (ii == 1)
            cout << b[i] << " is a prime number ";
        else
            cout << b[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[MAX];
    makespf(a, n);
}
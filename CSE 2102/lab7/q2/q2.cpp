#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100001
int primes[MAX];
int ii = 0;
void makespf(int a[], int n)
{
    a[1] = 1;
    int b[n];
    for (int i = 2; i < MAX; i++)
        a[i] = i;
    for (int j = 4; j < MAX; j += 2)
        a[j] = 2;

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
        primes[ii] = a[n];
        ii++;
        n = n / a[n];
    }
}

int modE(int b, int e, int ms)
{
    int result = 1;
    while (e > 0)
    {
        if (e % 2 == 1)
            result = (result * b) % ms;
        b = (b * b) % ms;
        e = e / 2;
    }
    return result;
}
int main()
{
    int a[MAX];
    int n, b;
    cin >> n >> b;
    makespf(a, n);
    long long mod = 1;
    for (int i = 0; i < ii; i++)
    {
        cout << "prime: " << primes[i] << endl;
        cout << "remainder: " << (n - 1) % (primes[i] - 1) << endl;
        if ((n - 1) % (primes[i] - 1) == 0)
            mod = mod * 1;
        else
            mod *= modE(b, (n - 1) % (primes[i] - 1), primes[i]);
        cout << "final: " << mod << endl;
    }
    if (mod == 1)
        cout << n << " is pseudo prime to base " << b << endl;
    else
        cout << n << " is not pseudo prime to base " << b << endl;
}
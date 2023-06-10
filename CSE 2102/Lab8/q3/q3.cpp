#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
int extend(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extend(b, a % b, x1, y1);
    cout << endl;
    cout << "x1: " << x1 << " y1: " << y1 << endl;
    cout << "a: " << a << " b: " << b << endl;
    x = y1;
    y = x1 - y1 * (a / b);
    cout << "x: " << x << " y: " << y << endl;
    return d;
}
bool coprime(int a, int b)
{

    if (__gcd(a, b) == 1)
        return true;
    else
        return false;
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
    int x, y;
    srand(time(NULL));
    int n, q[2], i = 0;
    while (1)
    {
        n = rand() % 100;
        if (isPrime(n))
        {
            q[i] = n;
            i++;
            cout << "p" << i << " : " << n << endl;
            if (i == 2)
                break;
        }
    }
    int j = 0, m = 2;
    cout << "Encryption : " << endl;
    cout << "n : " << q[0] * q[1] << endl;
    int key = (q[0] - 1) * (q[1] - 1);
    int kk = q[0] * q[1];
    while (1)
    {
        if (coprime(key, m))
        {
            j++;
            if (key > m)
            {
                cout << "e : " << m << endl;
                break;
            }
        }
        m++;
    }
    int dec = extend(m, key, x, y);
    while (x < 0)
        x = x + key;
    cout << "Decryption key : " << x << endl;
    int encryted = modE(2, m, kk);
    cout << "Encrypted message : "
         << encryted << endl;
    cout << "Decrypted message : " << modE(encryted, x, kk) << endl;
    return 0;
}
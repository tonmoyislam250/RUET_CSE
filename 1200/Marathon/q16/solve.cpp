#include <iostream>
using namespace std;
int fastpow(long long x, long long n, long long M)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    long long modn = fastpow(x, n / 2, M);
    if (n % 2 == 0)
        return (modn * modn) % M;
    else
        return (((modn * modn) % M) * x) % M;
}
int main()
{
    int n, b;
    cin >> b >> n;
    int result = fastpow(b, n, 1000000007);
    cout << result << endl;
}
#include <iostream>
using namespace std;
void printC(long long n)
{
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 != 0)
            n = 3 * n + 1;
        else
            n = n / 2;
    }
    cout << n;
}
int main()
{
    long long n;
    cin >> n;
    printC(n);
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long solve(int a[], int n)
{
    long long ans = a[0];
    for (int i = 1; i < n; i++)
        ans = ((a[i] * ans) / gcd(a[i], ans));
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(a, n) << endl;
}
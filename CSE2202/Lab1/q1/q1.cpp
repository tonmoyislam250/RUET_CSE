#include <bits/stdc++.h>
#include <chrono>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int Jum(int a[], int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += a[i];
    return s;
}
int Rsum(int a[], int k)
{
    if (k == 0)
        return 0;
    else
        return a[k] + Rsum(a, k - 1);
}

void solve()
{
    int k;
    cin >> k;
    int a[k];
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    cout << "sum = " << Jum(a, k) << endl;
}

int main()
{
    long long size;
    cin >> size;
    srand(time(0));
    ofstream output("input.txt");
    output << size << endl;
    for (int i = 0; i < size; i++)
        output << rand() << " ";
    output.close();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    auto start = std::chrono::high_resolution_clock::now();
    for (int it = 0; it < size; it++)
    {
        cout << "Case #" << it + 1 << ": ";
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Run time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
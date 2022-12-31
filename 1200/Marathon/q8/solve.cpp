#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
    int n, x, y, ans = 0, maxy = 0;
    cin >> n;
    vector<pair<int, bool>> a;
    while (n--)
    {
        cin >> x >> y;
        a.push_back(make_pair(x, true));
        a.push_back(make_pair(y, false));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].second == true)
        {
            ans++;
            maxy = max(maxy, ans);
        }
        else
        {
            ans--;
        }
    }
    cout << maxy << endl;
}
int main()
{
    solve();
}
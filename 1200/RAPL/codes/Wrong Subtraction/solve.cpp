#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void solve()
{
  int t, x;
  cin >> x >> t;
  for (int i = 1; i <= t; i++)
  {
    if (x % 10 != 0)
    {
      x = x - 1;
    }
    else
    {
      x = x / 10;
    }
  }
  cout << x << endl;
}
int main()
{
  solve();
}
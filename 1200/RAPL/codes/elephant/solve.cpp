#include <iostream>
using namespace std;
int solve(int x)
{
    int y = x / 5;
    if (x % 5 == 0)
    {
        return y;
    }
    else
    {
        int t = 5;
        while (t--)
        {
            // cout << t << endl;
            if (t == (x % 5))
            {
                y = y + 1;
                break;
            }
        }
    }
    return y;
}
int main()
{
    int s;
    cin >> s;
    cout << solve(s) << endl;
}
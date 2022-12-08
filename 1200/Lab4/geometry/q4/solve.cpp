#include <iostream>
using namespace std;
bool isInt(double q)
{
    int n = int(q);
    return (q - n == 0);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        int t1, t2;
        cin >> t1;
        double a1[t1];
        // cout << "Enter p" << endl;
        for (int i = 0; i < t1; i++)
            cin >> a1[i];
        cin >> t2;
        double a2[t2];
        // cout << "Enter q" << endl;
        for (int i = 0; i < t2; i++)
            cin >> a2[i];
        for (int j = 0; j < t1; j++)
        {
            for (int k = 0; k < t2; k++)
            {
                double x, y;
                // cout << "p and q " << a1[j] << " " << a2[k] << endl;
                x = (a2[k] - a1[j]) / 2;
                y = x + a1[j];
                // cout << x << " " << y << endl;
                if (isInt(x) == 1 && isInt(y) == 1)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        // cout << isInt(10.1) << endl;
    }
}
int main()
{
    solve();
}
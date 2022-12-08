#include <iostream>
using namespace std;
void solve()
{
    int r, c, i = 0, j = 0;
    int count = 0;
    cin >> r >> c;
    char s[r][c];
    int l = 0, w = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '*')
            {
                if (l==i )
                {
                    /* code */
                }
                l = i;
                w = j;
            }
            count++;
        }
    }
    cout << count << endl;
    if (count == 3)
    {
        cout<<
    }
}
int main()
{
    solve();
}

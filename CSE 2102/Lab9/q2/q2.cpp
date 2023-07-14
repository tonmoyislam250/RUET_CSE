#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    bool h = true;
    cin >> n;
    char inarr[n];
    memset(inarr, 'x', sizeof(inarr));
    inarr[0] = 'B';
    for (int ii = 0; ii < n; ii++)
    {
        if (inarr[ii] != 'x')
        {
            cout << "vertix " << ii + 1 << endl;
            int m;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                int edge;
                cin >> edge;
                if (inarr[edge - 1] == 'x')
                {
                    if (inarr[ii] == 'B')
                        inarr[edge - 1] = 'R';
                    else if (inarr[ii] == 'R')
                        inarr[edge - 1] = 'B';
                }
                else if (inarr[edge - 1] == inarr[ii])
                {
                    h = false;
                    cout << "hello" << endl;
                    break;
                }
            }
        }
    }
    if (h)
    {
        cout << "its bipartite" << endl;
    }
    else
        cout << "it is not bipartite" << endl;
}
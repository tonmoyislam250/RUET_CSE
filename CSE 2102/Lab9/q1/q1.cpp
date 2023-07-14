#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int inar[n];
    memset(inar, 0, sizeof(inar));
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int edge;
            cin >> edge;
            inar[edge - 1] += 1;
        }
        cout << "outward of " << i << ": " << m << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "inward of " << i << ": " << inar[i] << endl;
    }
}
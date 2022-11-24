#include <iostream>
using namespace std;
class LS
{
private:
    int x;

public:
    void get_data(int a)
    {
        x = a;
    }
    int lsearch(int a[], int s)
    {
        for (int i = 0; i < s; i++)
        {
            if (a[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    int n, x, y;
    cin >> n;
    int u[n];
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    cout << "enter value to search" << endl;
    cin >> x;
    LS test;
    test.get_data(x);
    y = test.lsearch(u, n);
    if (y == -1)
    {
        cout << "value not found" << endl;
    }
    else
    {
        cout << "the position is " << y << endl;
    }
}
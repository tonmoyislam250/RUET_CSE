#include <iostream>
#include <cstring>
#define n 20
using namespace std;
int main()
{
    cout << "Input array size" << endl;
    int i = 0, j = 0, k;
    cin >> k;
    int a[k], b[n];
    while (i < k)
    {
        cin >> a[i];
        i++;
    }
    memset(b, 0, sizeof(b));
    while (j < k)
    {
        b[a[j]]++;
        cout << b[a[j]] << " ";
        j++;
    }
    cout << endl;
}
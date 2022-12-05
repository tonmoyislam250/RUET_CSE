// C++ recursive function to
#include <iostream>
using namespace std;
int cnt = 0;
int towerOfHanoi(int n, char src, char des, char help)
{
    if (n != 0)
    {
        cnt++;
        towerOfHanoi(n - 1, src, help, des);
        cout << "Move Disk " << n << " from Source " << src
             << " to Destination " << des << endl;
        towerOfHanoi(n - 1, help, des, src);
    }
    return cnt;
}
int main()
{
    int N;
    cout << "Enter your Disk Numbers : ";
    cin >> N;
    int res = towerOfHanoi(N, 'A', 'C', 'B');
    cout << "Total moves taken is :  " << res << endl;
    return 0;
}

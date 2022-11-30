#include <iostream>
using namespace std;
long long ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if ((m > 0) && (n == 0))
    {
        return ackermann(m - 1, 1);
    }
    else if ((m > 0) && (n > 0))
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0;
}
int main()
{
    int A, x, y;
    cout << "Enter the value of m and n : ";
    cin >> x >> y;
    A = ackermann(x, y);
    cout << "The ackermann functional value is " << A << endl;
    return 0;
}
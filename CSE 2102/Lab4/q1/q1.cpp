#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int sum1 = 0, sum2 = 0, sum4 = 0, a, b, c, d;
    cout << "Input Range : ";
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= a; i++)
    {
        sum1 = 0;
        for (int j = 0; j <= b; j++)
        {
            sum1 += ((3 * j) + (4 * i));
        }
        sum2 += sum1;
    }
    cout << "The sum1 is = " << sum2 << endl;
    for (int ii = 1; ii <= c; ii++)
    {
        int sum3 = 0;
        for (int jj = 0; jj <= d; jj++)
        {
            sum4 += (pow(2, ii) + pow(3, jj));
        }
        sum4 += sum3;
    }
    cout << "The sum2 is = " << sum4 << endl;
}
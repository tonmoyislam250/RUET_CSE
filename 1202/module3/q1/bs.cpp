#include <iostream>
using namespace std;
class Binarys
{
private:
    int b, c, x;

public:
    void get_data(int beg, int end, int search)
    {
        b = beg;
        c = end;
        x = search;
    }
    int binar(int a[])
    {
        while (b <= c)
        {
            int m = (b + c) / 2;
            if (a[m] == x)
            {
                return m;
            }
            else if (a[m] < x)
            {
                b = m + 1;
            }
            else if (a[m] > x)
            {
                c = m - 1;
            }
        }
        return -1;
    }
};
int main()
{
    int n, x, result;
    cout << "************** BINARY SEARCH **************" << endl;
    cout << "\n\n";
    cout << "Enter Your Array Size :=" << endl;
    cin >> n;
    int beg = 0, end = n - 1;
    int y[n];
    cout << "Enter The Array Elements in a Sorted Manner :=" << endl;
    for (int i = 0; i < n; i++)
        cin >> y[i];
    cout << "Enter number to be searched :=" << endl;
    cin >> x;
    Binarys test;
    test.get_data(beg, end, x);
    result = test.binar(y);
    if (result == -1)
    {
        cout << "Value not found in the existing Array Or Your Array is not Sorted" << endl;
    }
    else
    {
        cout << "The Number is located at Index = " << result << endl;
    }
}
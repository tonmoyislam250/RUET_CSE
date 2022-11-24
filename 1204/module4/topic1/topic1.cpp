#include <iostream>
using namespace std;
class Test
{
public:
    int Sum(int a)
    {
        return a;
    }
    int Sum(int a, int b)
    {
        return a + b;
    }
    double Sum(double a, int b)
    {
        return a + b;
    }
    double Sum(int a, double b)
    {
        return a + b;
    }
    double Sum(double a, double b)
    {
        return a + b;
    }
};
int main()
{
    Test t;
    cout << "The Sum is " << t.Sum(10) << endl;
    cout << "The Sum is " << t.Sum(10, 20) << endl;
    cout << "The Sum is " << t.Sum(5.7, 20) << endl;
    cout << "The Sum is " << t.Sum(10, 2.6) << endl;
    cout << "The Sum is " << t.Sum(10.5, 20.7) << endl;
}
#include <iostream>
using namespace std;
template <typename G, typename R>
class A
{
    G x;
    R y;

public:
    void setData(G x, R y)
    {
        this->x = x;
        this->y = y;
    }
    R getSum()
    {
        return x + y;
    }
};
int main()
{
    A<int, int> a;
    a.setData(3, 4);
    cout << "The sum is " << a.getSum() << endl;
    A<int, double> b;
    b.setData(3, 4.4);
    cout << "The sum is " << b.getSum() << endl;
    A<double, double> c;
    c.setData(3.3, 4.4);
    cout << "The sum is " << c.getSum() << endl;
}
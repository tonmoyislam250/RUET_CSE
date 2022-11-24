#include <iostream>
using namespace std;
class A
{
private:
    int ax;

public:
    A()
    {
        ax = 12;
    }
    int getax() { return ax; }
    ~A()
    {
        cout << "A Destructor is Called" << endl;
    }
};
class B : public A
{
private:
    int bx;

public:
    B()
    {
        bx = 34;
    }
    int sum()
    {
        return getax() + bx;
    }
    ~B()
    {
        cout << "B Destructor is Called" << endl;
    }
};
int main()
{
    B b;
    cout << "The sum is = " << b.sum() << endl;
}
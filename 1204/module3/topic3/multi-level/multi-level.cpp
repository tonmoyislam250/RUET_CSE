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
    int getbx() { return bx; }
    ~B()
    {
        cout << "B Destructor is Called" << endl;
    }
};
class C : public B
{
private:
    int cx;

public:
    C()
    {
        cx = 56;
    }
    int sum()
    {
        return getax() + getbx() + cx;
    }
    ~C()
    {
        cout << "C Destructor is Called" << endl;
    }
};
int main()
{
    C c;
    cout << "The sum is = " << c.sum() << endl;
}
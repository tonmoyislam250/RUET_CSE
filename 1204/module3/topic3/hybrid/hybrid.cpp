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
class B : virtual public A
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
class C : virtual public A
{
private:
    int cx;

public:
    C()
    {
        cx = 56;
    }
    int getcx()
    {
        return cx;
    }
    ~C()
    {
        cout << "C Destructor is Called" << endl;
    }
};
class D : public B, public C
{
private:
    int dx;

public:
    D()
    {
        dx = 78;
    }
    int sum()
    {
        return getax() + getbx() + getcx() + dx;
    }
    ~D()
    {
        cout << "D Destructor is Called" << endl;
    }
};

int main()
{
    D d;
    cout << "The sum is = " << d.sum() << endl;
}
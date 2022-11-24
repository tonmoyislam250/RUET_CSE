#include <iostream>
using namespace std;
class A
{
public:
    virtual void print() = 0;
};
class B : public A
{
public:
    void print()
    {
        cout << "Inside Print() of class B" << endl;
    }
};
int main()
{
    // i)
    // A a;
    // a.print();
    // ii)
    B b;
    b.print();
    // iii)
    A *p;
    // p = &a;
    p->print();
    // iv)
    p = &b;
    p->print();
}
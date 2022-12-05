#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A()
    {
        x = 11;
    }
};

class B : public A
{
private:
    int y;

public:
    B()
    {
        // x = 11;
        y = 22;
        z = 33;
    }
    // int getx() { return x; }
    int gety() { return y; }
    int getz() { return z; }
};

int main()
{
    B test;
    cout << "protected y = " << test.gety() << endl;
    cout << "protected z = " << test.getz() << endl;
}
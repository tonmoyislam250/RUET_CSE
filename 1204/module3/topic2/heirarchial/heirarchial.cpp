// MU
#include <iostream>
using namespace std;

class A
{
private:
    int x = 1;

protected:
    int y = 2;

public:
    int z = 3;
};
class B : public A
{
public:
    int gety() { return y; }
};
class C : public A
{
public:
    int gety() { return y; }
};

int main()
{
    B b;
    C test;
    cout << "Private x not accessible out of base class" << endl;
    cout << "protected y = " << b.gety() << endl;
    cout << "public z = " << b.z << endl;
    cout << "protected y = " << test.gety() << endl;
    cout << "public z = " << test.z << endl;
}
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
class B
{
private:
    int p = 4;

protected:
    int q = 5;

public:
    int r = 6;
};

class C : public A, public B
{
public:
    int gety() { return y; }
    int getq() { return q; }
};

int main()
{
    C test;
    cout << "Private x, p not accessible out of base class" << endl;
    cout << "protected y = " << test.gety() << endl;
    cout << "public z = " << test.z << endl;
    cout << "protected q = " << test.getq() << endl;
    cout << "public r = " << test.r << endl;
}
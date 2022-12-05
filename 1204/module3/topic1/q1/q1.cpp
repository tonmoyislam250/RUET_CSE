#include <iostream>
using namespace std;
class Father
{
private:
    int money;

protected:
    int gold;

public:
    int land;

public:
    Father()
    {
        money = 1;
        gold = 2;
        land = 3;
    }
};
class Son : public Father
{
public:
    int get_prot()
    {
        return gold;
    }
};

class GrandSon1 : public Son
{
};
class GrandSon2 : protected Son
{
public:
    int get_prot()
    {
        return gold;
    }
    int get_prot2()
    {
        return land;
    }
};
class GrandSon3 : private Son
{
public:
    int get_private()
    {
        return gold;
    }
    int get_private2()
    {
        return land;
    }
};

int main()
{
    Son test2;
    GrandSon1 test3;
    GrandSon2 test4;
    GrandSon3 test5;
    cout << "Son Public Class from Father members" << endl;
    cout << "Private not accessible from Father" << endl;
    cout << "Protected = " << test2.get_prot() << endl;
    cout << "Public = " << test2.land << endl;
    cout << "GrandSon1 Public Class from Son members" << endl;
    cout << "Private not accessible from Father" << endl;
    cout << "Protected = " << test3.get_prot() << endl;
    cout << "Public = " << test3.land << endl;
    cout << "GrandSon2 Protected Class from Son members" << endl;
    cout << "Private not accessible from Father" << endl;
    cout << "Protected = " << test4.get_prot() << endl;
    cout << "Protected = " << test4.get_prot2() << endl;
    cout << "GrandSon3 Private Class from Son members" << endl;
    cout << "Private not accessible from Father" << endl;
    cout << "Private = " << test5.get_private() << endl;
    cout << "Private = " << test5.get_private2() << endl;
}

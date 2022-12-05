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
class Son : private Father
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

class GrandSon1 : public Son
{
public:
};
class GrandSon2 : protected Son
{
public:
};
class GrandSon3 : private Son
{
public:
};

int main()
{
    Son test2;
    GrandSon1 test3;
    GrandSon2 test4;
    GrandSon3 test5;
    cout << "Son Public Class from Father members" << endl;
    cout << "Private not accessible from FAther" << endl;
    cout << "Private = " << test2.get_private() << endl;
    cout << "Private = " << test2.get_private2() << endl;
    cout << "GrandSon1 Public Class from Son members" << endl;
    cout << "Private not accessible from Son" << endl;
    cout << "GrandSon2 Protected Class from Son members" << endl;
    cout << "Private not accessible from Son" << endl;
    cout << "GrandSon3 Private Class from Son members" << endl;
    cout << "Private not accessible from Son" << endl;
}

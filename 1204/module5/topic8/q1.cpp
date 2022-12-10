#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;
void display(list<int> j)
{
    list<int>::iterator k;
    for (k = j.begin(); k != j.end(); k++)
        cout << *k << " ";
    cout << endl;
}
void revdisplay(list<int> O)
{
    for (auto m = O.rbegin(); m != O.rend(); m++)
        cout << *m << " ";
    cout << endl;
}

int main()
{
    list<int> linkedli;
    for (int i = 1; i <= 16; i += 2)
    {
        linkedli.push_back(i);
    }
    display(linkedli);
    revdisplay(linkedli);
    cout << "Front = " << linkedli.front() << endl;
    cout << "Back = " << linkedli.back() << endl;
    linkedli.pop_back();
    linkedli.pop_front();
    linkedli.f

}
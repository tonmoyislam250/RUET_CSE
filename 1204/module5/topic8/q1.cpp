#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;
bool isOdd(int x)
{
    return (x % 2 != 0);
}
bool isEven(int x)
{
    return (x % 2 == 0);
}
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
    list<int> linkedli2;
    int a[17];
    a[0] = 1;
    a[1] = 3;
    for (int i = 1; i <= 16; i += 2)
        linkedli.push_back(i);
    for (int i = 2; i <= 16; i += 2)
    {
        a[i] = i;
        a[i + 1] = i + 2 * i;
        linkedli2.push_back(i);
    }
    linkedli.push_back(7);
    linkedli.push_back(7);
    display(linkedli);
    revdisplay(linkedli);
    cout << "Front = " << linkedli.front() << endl;
    cout << "Back = " << linkedli.back() << endl;
    linkedli.pop_back();
    linkedli.pop_front();
    display(linkedli);
    list<int>::iterator k;
    int x = 9;
    k = find(linkedli.begin(), linkedli.end(), 9);
    int y = distance(linkedli.begin(), k);
    cout << "Found at index " << y << "" << endl;
    linkedli.insert(k, 100);
    display(linkedli);
    linkedli.insert(next(k), 400);
    display(linkedli);
    cout << "7 is counted " << count(linkedli.begin(), linkedli.end(), 7) << " times" << endl;
    cout << "there are " << count_if(linkedli.begin(), linkedli.end(), isOdd) << " odd numbers" << endl;
    linkedli.erase(k);
    display(linkedli);
    list<int>::iterator range_end = linkedli.begin();
    advance(range_end, 4);
    linkedli.erase(linkedli.begin(), range_end);
    cout << "Deleted first 3 Elements " << endl;
    display(linkedli);
    linkedli.push_back(9);
    linkedli.push_back(12);
    linkedli.push_back(13);
    display(linkedli);
    linkedli.remove(x);
    linkedli.remove_if(isEven);
    display(linkedli);
    linkedli.assign(linkedli2.begin(), linkedli2.end());
    display(linkedli);
    linkedli.assign(a, a + 17);
    cout << "Before sorting : " << endl;
    display(linkedli);
    linkedli.sort();
    cout << "After sorting : " << endl;
    display(linkedli);
    cout << "Before Unique : " << endl;
    display(linkedli);
    linkedli.unique();
    cout << "After Unique : " << endl;
    display(linkedli);
}
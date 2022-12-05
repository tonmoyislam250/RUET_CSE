#include <iostream>
#include <utility>
using namespace std;
int main()
{
    pair<int, string> pa = make_pair(10, "Rajshahi");
    cout << "Before Swap" << endl;
    cout << "First Data : " << pa.first << endl;
    cout << "Second Data : " << pa.second << endl;
    get<int>(pa) = 20;
    pair<int, string> pb = make_pair(30, "Khulna");
    pa.swap(pb);
    cout << "After Swap" << endl;
    cout << "First Data : " << pa.first << endl;
    cout << "Second Data : " << pa.second << endl;
}
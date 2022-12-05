#include <iostream>
#include <utility>
#include <tuple>
using namespace std;
int main()
{
    tuple<int, string, double> tx;
    tx = make_tuple(100, "Kamal", 3.5);
    cout << "Before Swap" << endl;
    cout << "First Data : " << get<int>(tx) << endl;
    cout << "Second Data : " << get<string>(tx) << endl;
    cout << "Third Data : " << get<double>(tx) << endl;
    get<double>(tx) = 3.7;
    tuple<int, string, double> bx = make_tuple(200, "Emon", 5.6);
    tx.swap(bx);
    cout << "After Swap" << endl;
    cout << "First Data : " << get<int>(tx) << endl;
    cout << "Second Data : " << get<string>(tx) << endl;
    cout << "Third Data : " << get<double>(tx) << endl;
}
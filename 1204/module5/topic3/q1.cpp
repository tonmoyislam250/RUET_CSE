#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 6> ar = {10, 60, 30, 70, 20}, ar1 = {1, 6, 3, 7, 2};
    cout << "The third element  is : " << ar.at(2) << endl;
    cout << "The First element is : " << ar.front() << endl;
    cout << "The Last element is : " << ar.back() << endl;
    if (ar.empty())
    {
        cout << "Array is empty";
    }
    cout << "Before Swap" << endl;
    for (auto i = 0; i < ar.size(); i++)
        if (ar[i] != 0)
            cout << ar[i] << " ";
    cout << endl;
    ar.fill(100);
    cout << "After Filling 100" << endl;
    for (auto i = 0; i < ar.size(); i++)
        if (ar[i] != 0)
            cout << ar[i] << " ";
    cout << endl;
    ar.swap(ar1);
    cout << "After Swap" << endl;
    for (auto i = 0; i < ar.size(); i++)
        if (ar[i] != 0)
            cout << ar[i] << " ";
    cout << endl;
    cout << "The size of the array = " << ar.size() << endl;
    cout << "The maximum size of the array = " << ar.size() << endl;
    cout << "The address of the first element of the array is " << ar.begin() << endl;
    cout << "The address of the last element of the array is " << ar.end() << endl;
}
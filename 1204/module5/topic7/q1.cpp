#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> hello;
    for (int i = 1; i <= 6; i++)
        hello.push(i);
    cout << hello.size() << " " << hello.back() << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << hello.front() << " ";
        hello.pop();
    }
    cout << endl;
    if (hello.empty())
    {
        cout << "Stack is Empty" << endl;
    }
}
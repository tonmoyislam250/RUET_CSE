#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    for (int i = 0; i < 10; i++)
        st.push(i);
    cout << "Before Pop and After Push" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    if (st.empty())
    {
        cout << "Stack is Empty" << endl;
    }
}
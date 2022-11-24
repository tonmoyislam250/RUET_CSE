#include <iostream>
using namespace std;
int n;
int stack[0];
void init_stack()
{
    cout << "Enter the stack size: ";
    cin >> n;
    stack[n];
}
void menu()
{
    cout << "***Stack Menu***" << endl;
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
    cout << "Enter Your Option -> ";
}
class Stack
{
private:
    int top = -1;

public:
    void push()
    {
        int val;
        cout << "Enter your stack value : ";
        cin >> val;
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "The poped element is : " << stack[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top >= 0)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << "| " << stack[i] << " |" << endl;
                cout << "_____" << endl;
            }
        }
        else
            cout << "Stack is Empty.." << endl;
    }
};
int main()
{
    system("clear");
    Stack a;
    int m;
    while (m != 4)
    {
        menu();
        cin >> m;
        switch (m)
        {
        case 1:
            if (n == 0)
                init_stack();
            a.push();
            break;
        case 2:
            a.pop();
            break;
        case 3:
            a.display();
            break;
        case 4:
            break;
        }
    }
    return 0;
}
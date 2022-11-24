#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
class Polish
{
private:
    int top = -1, top2 = -1;
    int stack[200];
    string sstack[200];

public:
    void push(int x)
    {
        top++;
        stack[top] = x;
    }
    int pop()
    {
        return stack[top--];
    }
    void spush(string x)
    {
        top2++;
        sstack[top2] = x;
    }
    string spop()
    {
        return sstack[top2--];
    }
    bool isOperand(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    void postcalc(string s)
    {
        int size = s.length();
        int num, i = 0, a, b, c;
        while (i < size)
        {
            if (isdigit(s[i]))
            {
                num = s[i] - 48;
                push(num);
            }
            else if (isalpha(s[i]))
            {
                cout << "value determination is not possible" << endl;
                break;
            }
            else
            {
                a = pop();
                b = pop();
                switch (s[i])
                {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = b - a;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = b / a;
                    break;
                case '^':
                    c = pow(a, b);
                    break;
                }
                push(c);
            }
            i++;
        }
        cout << "The Value of that Postfix expression : " << pop() << endl;
    }
    void precalc(string s)
    {
        int size = s.length();
        int num, i = size - 1, a, b, c;
        while (i >= 0)
        {
            // cout << s[i] << endl;
            if (isdigit(s[i]))
            {
                num = s[i] - 48;
                push(num);
            }
            else if (isalpha(s[i]))
            {
                cout << "value determination is not possible" << endl;
                break;
            }
            else
            {
                a = pop();
                b = pop();
                switch (s[i])
                {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = a / b;
                    break;
                case '^':
                    c = pow(a, b);
                    break;
                }
                push(c);
            }
            i--;
        }
        cout << "The Value of that Prefix expression : " << pop() << endl;
    }
    string postoinf(string postfix)
    {
        int n = postfix.size();
        string infix;
        for (int i = 0; i < n; i++)
        {
            if (isOperand(postfix[i]))
            {
                string op(1, postfix[i]);
                spush(op);
            }
            else
            {
                string s1 = spop(), s2 = spop();
                spush("(" + s2 + postfix[i] + s1 + ")");
            }
        }
        return sstack[top2];
    }
    string pretoinf(string prefix)
    {
        int n = prefix.size();
        string infix;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isOperand(prefix[i]))
            {
                string op(1, prefix[i]);
                spush(op);
            }
            else
            {
                string s1 = spop(), s2 = spop();
                spush("(" + s1 + prefix[i] + s2 + ")");
            }
        }
        return sstack[top2];
    }
};

int main()
{
    string s;
    int choice;
    Polish test;
    cout << "What do you gonna Input?\n1. Postfix\n2. Prefix" << endl;
    cout << "Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter your Postfix Expression : ";
        cin >> s;
        cout << "The infix expression is : " << test.postoinf(s) << endl;
        test.postcalc(s);
        break;
    case 2:
        cout << "Enter your Prefix Expression : ";
        cin >> s;
        cout << "The infix expression is : " << test.pretoinf(s) << endl;
        test.precalc(s);
        break;
    }
}
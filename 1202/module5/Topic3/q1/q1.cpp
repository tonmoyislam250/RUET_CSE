#include <iostream>
using namespace std;
class INFtoPOST
{
private:
    int top = -1;
    int stack[200];

public:
    void push(char x)
    {
        top++;
        stack[top] = x;
    }
    void pop()
    {
        stack[top--];
    }
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    bool isOperand(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    string reverseStr(string str)
    {
        int u = str.length();
        for (int i = 0; i < u / 2; i++)
            swap(str[i], str[u - i - 1]);
        return str;
    }
    string infixToPostfix(string infix)
    {
        int n = infix.size();
        string postfix;
        for (int i = 0; i < n; i++)
        {
            if (isOperand(infix[i]))
                postfix.push_back(infix[i]);
            else if (infix[i] == '(')
                push('(');
            else if (infix[i] == ')')
            {
                while (stack[top] != '(')
                {
                    postfix.push_back(stack[top]);
                    pop();
                }
                pop();
            }
            else
            {
                while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i]))
                {
                    postfix.push_back(stack[top]);
                    pop();
                }
                push(infix[i]);
            }
        }
        while (top != -1)
        {
            postfix.push_back(stack[top]);
            pop();
        }
        return postfix;
    }
    string infixToPrefix(string infix)
    {
        infix = reverseStr(infix);
        int l = infix.size();
        for (int i = 0; i < l; i++)
        {

            if (infix[i] == '(')
            {
                infix[i] = ')';
            }
            else if (infix[i] == ')')
            {
                infix[i] = '(';
            }
        }
        infix = infixToPostfix(infix);
        return reverseStr(infix);
    }
};
int main()
{
    string infix;
    cout << "Enter your Infix Expression : ";
    getline(cin, infix);
    INFtoPOST a;
    string postfix = a.infixToPostfix(infix);
    string prefix = a.infixToPrefix(infix);
    cout << "Infix expression : " << infix << endl;
    cout << "Postfix expression : " << postfix << endl;
    cout << "Prefix expression : " << prefix << endl;
    return 0;
}
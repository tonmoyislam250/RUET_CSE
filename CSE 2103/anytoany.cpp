#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> sou;
string ALPHA = "ABCDEF";
void div(string n, int b, int d)
{
    int L = n.length();
    int r = 0;
    string q = "";
    for (int i = 0; i < L; i++)
    {
        int digit = (isdigit(n[i])) ? (n[i] - '0') : (n[i] - 'A' + 10);
        r = r * b + digit;
        int q2 = r / d;
        r = r % d;
        q += (q2 < 10) ? ('0' + q2) : ('A' + q2 - 10);
    }
    cout<<q<<" = "<<r<<endl;
    int qL = q.length();
    int qS = 0;
    while (qS < qL && q[qS] == '0')
        qS++;
    sou.push(r);
    if (qS != qL)
        div(q, b, d);
}
void print(int div)
{
    while (!sou.empty())
    {
        if (div == 16)
        {
            if (sou.top() > 10)
            {
                cout << ALPHA[sou.top() - 10];
            }
            else
                cout << sou.top();
        }
        else
            cout << sou.top();
        sou.pop();
    }
}
int main()
{
    string n;
    bool t = true;
    int b, d;
    cout << "Enter number : original base : converted base" << endl;
    cin >> n >> b >> d;
    for (int i = 0; i < n.length() - 1; i++)
    {
        if ((n[i] - '0') > b)
        {
            t = false;
            break;
        }
    }
    if (t)
    {
        div(n, b, d);
        print(d);
    }
    else
        cout << "The digits are out of Base" << endl;
    return 0;
}
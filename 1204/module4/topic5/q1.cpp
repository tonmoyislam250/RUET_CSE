#include <iostream>
using namespace std;
class A
{
private:
    int x;

public:
    A()
    {
        x = 0;
    }
    void display()
    {
        cout << "The final result is : = " << x << endl;
    }
    friend void Add(A &a);
    friend void Inc(A &a);
    friend void Dec(A &a);
};
void Add(A &a)
{
    cout << "Input your assigning Value : >" << endl;
    int v;
    cin >> v;
    a.x = v;
}
void Inc(A &a)
{
    cout << "Input your Increased Value : >" << endl;
    int m;
    cin >> m;
    a.x = a.x + m;
}
void Dec(A &a)
{
    cout << "Input your Decreased Value : >" << endl;
    int n;
    cin >> n;
    a.x = a.x - n;
}
int main()
{
    A s;
    Add(s);
    Inc(s);
    Dec(s);
    s.display();
}
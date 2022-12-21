#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
};
class linking
{
public:
    node *h = NULL;

public:
    void create(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            node *q = new node;
            q->data = x;
            q->prev = NULL;
            q->next = NULL;
            if (h == NULL)
            {
                h = q;
            }
            else
            {
                node *p = h;
                while (1)
                {
                    if (p->data >= x)
                    {
                        if (p->prev == NULL)
                        {
                            p->prev = q;
                            break;
                        }
                        else
                        {
                            p = p->prev;
                        }
                    }
                    else
                    {
                        if (p->next == NULL)
                        {
                            p->next = q;
                            break;
                        }
                        else
                        {
                            p = p->next;
                        }
                    }
                }
            }
        }
    }
    void display(int n)
    {
        node *stack[100];
        cout << h << endl;
        node *m = h;
        int top = -1;
        for (int i = 0; i < n; i++)
        {
            if (m == NULL)
            {
                if (top != 0)
                {
                    m = stack[top];
                    cout << m->data << " ";
                    top -= 1;
                    m = m->next;
                }
            }
            else
            {
                top += 1;
                stack[top] = m;
                m = m->prev;
            }
        }
        cout << endl;
    }
};
// 70 35 97 88 44 32 90 15 30 60
int main()
{
    linking test;
    int n;
    cout << "How many nodes :";
    cin >> n;
    cout << "enter nodes : ";
    test.create(n);
    test.display(n);
}
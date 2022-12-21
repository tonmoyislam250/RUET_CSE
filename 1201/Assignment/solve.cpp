#include <iostream>
using namespace std;
class node
{
public:
    int coefficient;
    int power;
    node *next;
};
class algebra
{
public:
    node *h = NULL, *t = NULL;

public:
    void createNode(int size)
    {
        cout << "Enter Coefficient and Power : ";
        for (int i = 0; i < size; i++)
        {
            node *p = new node;
            int x, y;
            cin >> x >> y;
            p->coefficient = x;
            p->power = y;
            p->next = NULL;
            if (h == NULL)
            {
                h = p;
                cout << h << endl;
            }
            if (t == NULL)
            {
                t = p;
            }
            else
            {
                t->next = p;
                t = p;
            }
        }
    }
    void display()
    {
        node *u = h;
        while (u != NULL)
        {
            cout << u->coefficient << "x^" << u->power << "+";
            u = u->next;
        }
    }
    void add(algebra &obj)
    {
        node *n = h;
        while (n != NULL)
        {
            node *m = obj.h;
            node *prev = m;
            while (m != NULL)
            {
                if (n->power == m->power)
                {
                    n->coefficient = n->coefficient + m->coefficient;
                    if (m == obj.h)
                    {
                        h = m->next;
                    }
                    else
                    {
                        prev->next = m->next;
                    }
                }
                else if (n->power > m->power)
                {
                    m->next = n->next;
                    n->next = m;
                    break;
                }
                prev = m;
                m = m->next;
            }
            n = n->next;
        }
    }
};
int main()
{
    int w;
    int n;
    cout << "How many Expressions :";
    cin >> n;
    algebra test[n];
    algebra result;
    for (int i = 0; i < n; i++)
    {
        cout << "Experssion : " << i + 1 << endl;
        cout << "How many terms : ";
        cin >> w;
        test[i].createNode(w);
    }
    for (int i = 0; i < n; i++)
    {
        test[i].display();
        cout << endl;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        test[0].add(test[i]);
    }
    test[0].display();
    cout << endl;
}
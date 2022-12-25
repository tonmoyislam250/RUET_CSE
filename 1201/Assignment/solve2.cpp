#include <iostream>
using namespace std;
class node
{
public:
    int co;
    int po;
    node *next;
};
void get(node *p)
{
    int coefficient, power, cont;
    do
    {
        node *n = new node();
        cout << "coefficient : ";
        cin >> coefficient;
        cout << "power : ";
        cin >> power;
        p->co = coefficient;
        p->po = power;
        p->next = NULL;
        cout << "Want more terms press 1 for y and 0 for n : ";
        cin >> cont;
        if (cont)
        {
            p->next = n;
            p = n;
            p->next = NULL;
        }
    } while (cont);
}
void print(node *h)
{
    while (h != NULL)
    {
        cout << h->co << "x^" << h->po;
        h = h->next;
        if (h != NULL)
            cout << "+";
    }
}
void add(node *p, node *p1, node *p2)
{
    p->next = NULL;
    while (p1 && p2)
    {
        node *w = new node();
        if (p1->po > p2->po)
        {
            p->co = p1->co;
            p->po = p1->po;
            p1 = p1->next;
        }
        else if (p1->po < p2->po)
        {
            p->co = p2->co;
            p->po = p2->po;
            p2 = p2->next;
        }
        else
        {
            p->co = p1->co + p2->co;
            p->po = p1->po;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 && p2)
        {
            p->next = w;
            p = w;
            p->next = NULL;
        }
    }
    while (p1 || p2)
    {
        node *ww = new node();
        p->next = ww;
        p = ww;
        p->next = NULL;

        if (p1)
        {
            p->co = p1->co;
            p->po = p1->po;
            p1 = p1->next;
        }

        else if (p2)
        {
            p->co = p2->co;
            p->po = p2->po;
            p2 = p2->next;
        }
    }
}
int main()
{
    node *first = new node();
    node *second = new node();
    node *result = new node();
    printf("\nEnter the corresponding data:-\n");
    printf("\nFirst polynomial:\n");
    get(first);
    print(first);
    printf("\nSecond polynomial:\n");
    get(second);
    print(second);
    cout << endl;
    add(result, first, second);
    print(result);
    return 0;
}
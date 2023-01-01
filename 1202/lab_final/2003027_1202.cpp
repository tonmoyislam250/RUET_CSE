#include <iostream>
using namespace std;
#include <stack>
int ax[100];
int queue[100];
class node
{
public:
    int data;
    node *next;
};
class node2
{
public:
    node2 *prev;
    int data;
    node2 *next;
};
int rear = -1, front = -1;
node *head, *tail;
node2 *head2 = NULL;
void array_store()
{
    for (int i27 = 1; i27 <= 100; i27++)
        ax[i27] = i27;
    for (int i27 = 1; i27 <= 100; i27++)
        cout << ax[i27] << " ";
    cout << endl;
}
void enqueue(int y)
{
    if ((rear == 100 - 1 && front == 0) || (front == rear + 1))
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % 100;
        queue[rear] = y;
    }
}
void display()
{
    int i27 = front;
    cout << "front = " << front << endl;
    cout << "rear  = " << rear << endl;
    cout << "| TC |-> ";
    if (front == -1)
    {
        cout << "Queue is empty..." << endl;
    }
    else
    {
        while (i27 != rear)
        {
            cout << "| " << queue[i27] << "  ";
            i27 = (i27 + 1) % 100;
        }
        cout << "| " << queue[i27] << "  ";
        cout << "|" << endl;
    }
}
int dequeue()
{
    int x, y = 0;
    if (front == -1)
        printf("Queue is empty..\n");
    else
    {
        if (front == rear)
        {
            y = queue[front];
            front = -1;
            rear = -1;
            return y;
        }
        else
        {
            x = queue[front];
            front = (front + 1) % 100;
            return x;
        }
    }
    return 0;
}
void create_linked(int x)
{
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
    }
    if (tail == NULL)
    {
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}
void Display()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "Can't Display nodes" << endl;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void create(int x)
{
    node2 *q = new node2;
    node2 *p;
    q->data = x;
    q->prev = NULL;
    q->next = NULL;
    if (head2 == NULL)
    {
        head2 = q;
    }
    else
    {
        p = head2;
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
void display3()
{
    stack<node2 *> st;
    node2 *m = head2;
    cout << "value "
         << "own address "
         << "left address "
         << "Right address " << endl;
    if (m == NULL)
        cout << "Tree is Empty" << endl;
    while (m != NULL || st.empty() != true)
    {
        if (m != NULL)
        {
            st.push(m);
            m = m->prev;
        }
        else
        {
            m = st.top();
            cout << m->data << " " << m << " " << m->prev << " " << m->next << endl;
            st.pop();
            m = m->next;
        }
    }
    cout << endl;
}

int main()
{
    array_store();
    for (int i27 = 1; i27 <= 100; i27++)
    {
        enqueue(ax[i27]);
    }
    display();
    for (int i27 = 1; i27 <= 100; i27++)
    {
        int x = dequeue();
        if (x % 2 == 0)
        {
            create_linked(x);
        }
    }
    Display();
    display();
    node *temp = head;
    while (temp != NULL)
    {
        create(temp->data);
        temp = temp->next;
    }
    display3();                                                                                                                                                                         
}
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


int main()
{
    array_store();
    for (int i27 = 1; i27 <= 100; i27++)
    {
        enqueue(ax[i27]);
    }
    for (int i27 = 1; i27 <= 100; i27++)
    {
        int x = dequeue();
        if (x % 2 == 0)
        {
            create_linked(x);
        }
    }
    node *temp = head;
    while (temp != NULL)
    {
        create(temp->data);
        temp = temp->next;
    }
}
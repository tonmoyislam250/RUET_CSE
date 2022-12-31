#include <iostream>
using namespace std;
int ax[100];
int queue[100];
class node
{
public:
    int data;
    node *next;
};
int rear = -1, front = -1;
node *head, *tail;
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
}
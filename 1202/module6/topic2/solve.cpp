#include <iostream>
using namespace std;
class quelink
{
public:
    int data;
    quelink *next;
};
class TicketCounter
{
private:
    quelink *front = NULL, *rear = NULL;

public:
    void enqueue(int x)
    {
        quelink *temp = new quelink;
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            quelink *temp = front;
            if (temp->data == rear->data)
            {
                front = NULL;
                rear = NULL;
                cout << "Line was Emptied" << endl;
            }
            else
            {
                front = front->next;
                cout << "the data ( " << temp->data << " ) has been destroyed" << endl;
                delete (temp);
            }
        }
    }
    void display()
    {
        if (front != NULL && rear != NULL)
        {
            cout << "Front =" << front->data << endl;
            cout << "Rear = " << rear->data << endl;
        }
        quelink *iterate = front;
        if (iterate == NULL)
        {
            cout << "Counter is empty" << endl;
        }
        else
        {
            while (iterate != NULL)
            {
                cout << "| " << iterate->data << "  ";
                cout << iterate->next << endl;
                iterate = iterate->next;
            }
            cout << "|" << endl;
        }
    }
};
void menu()
{
    cout << "***Simple Queue Menu***" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
    cout << "Enter Your Option -> ";
}
int main()
{
    int choice, r, x;
    TicketCounter test;
    while (choice != 4)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter your Enqueued Value : ";
            cin >> x;
            test.enqueue(x);
            break;
        case 2:
            test.dequeue();
            break;
        case 3:
            cout << "Your Displayed Queue is :" << endl;
            test.display();
            break;
        }
    }
}
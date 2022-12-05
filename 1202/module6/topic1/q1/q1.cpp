#include <iostream>
using namespace std;
int n, queue[0];
void sizer()
{
    cout << "Enter your Queue Size : ";
    cin >> n;
    queue[n];
}
void menu()
{
    cout << "***Simple Queue Menu***" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
    cout << "Enter Your Option -> ";
}
class Queue
{
private:
    int rear = -1, front = -1;

public:
    void enqueue(int y)
    {
        if (rear == n - 1)
        {
            printf("Queue is full.\n");
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = y;
        }
    }

    void dequeue()
    {
        int x, y = 0;
        if (front == -1)
            printf("Queue is empty..\n");
        else
        {
            if (front >= rear)
            {
                y = queue[front];
                front = -1;
                rear = -1;
                cout << "Your Dequeued Value is :" << y << endl;
                cout << "his work (" << y << ") is done" << endl;
                cout << "Queue was emptied so it is initializing ...." << endl;
            }
            else
            {
                x = queue[front];
                front++;
                cout << "Your Dequeued Value is :" << x << endl;
                cout << "his work (" << x << ") is done" << endl;
            }
        }
    }
    void display()
    {
        int i = front;
        cout << "front = " << front << endl;
        cout << "rear  = " << rear << endl;
        cout << "| TC |-> ";
        if (front == -1)
        {
            cout << "Queue is empty..." << endl;
        }
        else
        {
            while (i <= rear)
            {
                cout << "| " << queue[i] << "  ";
                i++;
            }
            cout << "|" << endl;
        }
    }
};
int main()
{
    Queue test;
    int choice, r, x;
    while (choice != 4)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (n == 0)
                sizer();
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
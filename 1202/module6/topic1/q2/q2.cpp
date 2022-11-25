#include <iostream>
using namespace std;
void menu()
{
    cout << "***Stack Menu***" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
    cout << "Enter Your Option -> ";
}
class Queue
{
private:
    int rear = -1, front = -1, n = 3, a[3];

public:
    // void sizer()
    // {
    //     cout << "Enter your Queue Size : " << endl;
    //     cin >> n;
    //     a[];
    // }
    void enqueue(int y)
    {
        if (rear == n - 1)
        {
            rear = 0;
            if (rear == front)
            {
                printf("Queue is full.\n");
                rear = n - 1;
            }
            else
            {
                a[rear] = y;
            }
        }
        else
        {
            if (rear + 1 == front)
                printf("Queue is full.\n");
            else
                a[rear++] = y;
        }
    }

    int dequeue()
    {
        int x;
        if (rear == front)
            printf("Queue is empty..\n");
        else
        {
            if (front == n - 1)
                front = 0;
            else
                front++;
            x = a[front];
        }
        return x;
    }
    void display()
    {
        int i = front + 1;
        while (i <= rear)
        {
            cout << a[i] << endl;
            i++;
        }
        cout << endl;
    }
};
int main()
{
    Queue test;
    int choice, x;
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
            cout << "Your Dequeued Value is :";
            break;
        case 3:
            cout << "Your Displayed Queue is :" << endl;
            test.display();
            break;
        }
    }
}
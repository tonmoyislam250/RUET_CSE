#include <iostream>
using namespace std;
int n = 5;
int stack[0];
class node
{
public:
    int data;
    node *next;
    node *previ;
};

void menu()
{
    cout << "***Stack Menu***" << endl;
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
    cout << "Enter Your Option -> ";
}
class Stack
{
private:
    int top = -1;
    node *head, *tail;

public:
    Stack()
    {
        head = NULL;
        tail = NULL;
    }
    void push()
    {
        int val;
        cout << "Enter your stack value : ";
        cin >> val;
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            node *tmp = new node;
            tmp->data = val;
            tmp->previ = NULL;
            tmp->next = NULL;
            if (head == NULL)
            {
                head = tmp;
            }
            if (tail == NULL)
            {
                tail = tmp;
                top++;
            }
            else
            {
                tail->next = tmp;
                tmp->previ = tail;
                tail = tmp;
                top++;
            }
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "The poped element is : " << tail->data << endl;
            tail = tail->previ;
            top--;
        }
    }
    void display()
    {
        node *temp = tail;
        if (top >= 0)
        {
            while (temp->previ != NULL)
            {
                cout << "| " << temp->data << " |" << endl;
                cout << "_____" << endl;
                temp = temp->previ;
            }
            cout << "| " << head->data << " |" << endl;
            cout << "_____" << endl;
        }
        else
            cout << "Stack is Empty.." << endl;
    }
};
int main()
{
    system("clear");
    Stack a;
    int m;
    while (m != 4)
    {
        menu();
        cin >> m;
        switch (m)
        {
        case 1:
            a.push();
            break;
        case 2:
            a.pop();
            break;
        case 3:
            a.display();
            break;
        case 4:
            break;
        }
    }
    return 0;
}
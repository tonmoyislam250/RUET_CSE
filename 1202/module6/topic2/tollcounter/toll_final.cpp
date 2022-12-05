#include <iostream>
using namespace std;
class quelink
{
public:
    int data;
    string date = "Ticket counter is off";
    quelink *next;
};
class TicketCounter
{
private:
    quelink *front = NULL, *rear = NULL;
    int heavy = 0, medium = 0, light = 0;

public:
    void display_earning()
    {
        int cho;
        cout << "Which toll's earning you want to see\n1.Heavy\n2.Medium\n3.Light\n4.Total\nOption : ";
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "Heavy Counter Earning is : " << heavy << endl;
            break;
        case 2:
            cout << "Medium Counter Earning is : " << medium << endl;
            break;
        case 3:
            cout << "Light Counter Earning is : " << light << endl;
            break;
        case 4:
            cout << "Total Earning is " << heavy + medium + light << endl;
            break;
        }
    }
    string currentDateTime()
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d  %r", &tstruct);
        return buf;
    }
    bool check(int b)
    {
        quelink *op = front;
        while (op != NULL)
        {
            if (op->data == b)
            {
                return true;
            }
            else
            {
                op = op->next;
            }
        }
        return false;
    }
    void enqueue(int x)
    {
        quelink *temp = new quelink;
        if (check(x) == true)
            cout << "Car number is already in use" << endl;
        else
        {
            temp->data = x;
            temp->date = currentDateTime();
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
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Line is Empty" << endl;
        }
        else
        {
            int cho;
            cout << "Which kind of toll?\n1.heavy(800tk)\n2.medium(500)\n3.light(300tk)\nEnter option :";
            cin >> cho;
            switch (cho)
            {
            case 1:
                heavy += 800;
                break;
            case 2:
                medium += 500;
                break;
            case 3:
                light += 300;
                break;
            }
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
                cout << "the toll of car number = ( " << temp->data << " ) has been received" << endl;
                delete (temp);
            }
        }
    }
    void none()
    {
        quelink *t = front;
        cout << "| TC |-> ";
        if (front == NULL)
            cout << "Line is empty" << endl;
        else
        {
            while (t != NULL)
            {
                cout << "| " << t->data << "  ";
                t = t->next;
            }
            cout << "|" << endl;
        }
    }
    void display()
    {
        bool g;
        // if (front != NULL && rear != NULL)
        // {
        //     cout << "Front =" << front->data << endl;
        //     cout << "Rear = " << rear->data << endl;
        // }
        quelink *iterate = front;
        if (iterate == NULL)
        {
            cout << "Counter is empty" << endl;
        }
        else
        {
            int chi;
            cout << "Which car details your want to see : ";
            cin >> chi;
            while (iterate != NULL)
            {
                g = true;
                if (iterate->data == chi)
                {
                    cout << "Car Number : " << iterate->data << endl;
                    cout << "Ticket Number 20220" << iterate->data << endl;
                    cout << "Time " << iterate->date << endl;
                    // cout << iterate->next << endl;
                    break;
                }
                else
                {
                    g = false;
                }
                iterate = iterate->next;
            }
            if (g == false)
                cout << "car is not in the line" << endl;
            cout << endl;
        }
    }
};
void menu()
{
    cout << "***Simple Ticket counter***" << endl;
    cout << "1. Enter \n2. Receive\n3. Display\n4. Earnings\n5. Exit" << endl;
    cout << "Enter Your Option -> ";
}
int main()
{
    int choice, r, x;
    TicketCounter test;
    while (choice != 5)
    {
        test.none();
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter car number (1,2,3...): ";
            cin >> x;
            test.enqueue(x);
            break;
        case 2:
            test.dequeue();
            break;
        case 3:
            cout << "ticket counter line" << endl;
            test.display();
            break;
        case 4:
            test.display_earning();
            break;
        }
    }
}
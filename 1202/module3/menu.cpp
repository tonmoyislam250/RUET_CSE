#include <iostream>
using namespace std;

class LS
{
private:
    int x, n, b, c;
    int a[100];

public:
    void set_data()
    {
        int a;
        cout << "Enter value to search: " << endl;
        cin >> a;
        x = a;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }
    void get_data()
    {
        cout << "Enter your array size:" << endl;
        cin >> n;
        b = 0;
        c = n - 1;
        cout << "Enter the array elements in sorted manner(max 100):" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    int lsearch()
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
    int binar()
    {
        while (b <= c)
        {
            int m = (b + c) / 2;
            if (a[m] == x)
            {
                return m;
            }
            else if (a[m] < x)
            {
                b = m + 1;
            }
            else if (a[m] > x)
            {
                c = m - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int x, n, y, choice;
    LS test;
    while (choice != 5)
    {
        cout << "*** Menu ***" << endl;
        cout << "1. Create Array" << endl;
        cout << "2.linear search" << endl;
        cout << "3. Binary Search" << endl;
        cout << "4. Display Array" << endl;
        cout << "5. Exit" << endl;
        cout << "\n\nEnter your Option" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            test.get_data();
            break;
        case 2:
            test.set_data();
            y = test.lsearch();
            if (y == -1)
            {
                cout << "value not found" << endl;
            }
            else
            {
                cout << "the position is " << y << endl;
            }
            break;
        case 3:
            test.set_data();
            test.binar();
            y = test.lsearch();
            if (y == -1)
            {
                cout << "value not found" << endl;
            }
            else
            {
                cout << "the position is " << y << endl;
            }
            break;
        case 4:
            test.display();
        case 5:
            cout << "exiting..." << endl;
        }
    }
}
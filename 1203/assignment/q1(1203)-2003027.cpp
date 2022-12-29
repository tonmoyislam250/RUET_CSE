#include <iostream>
using namespace std;
class employee
{
public:
    string name;
    int age, salary, code;
    int code2 = 0;

public:
    void addemployee()
    {
        cout << "Enter your Name :";
        cin >> name;
        cout << "Enter your age,Salary and code";
        cin >> age >> salary >> code;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Salary : " << salary << endl;
        cout << "age : " << age << endl;
    }
};
class manager : public employee
{
public:
    employee *ref[10];
    int k = 0;

public:
    void addrefemp(employee m[], int s, int sup)
    {
        cout << "Which employee you want to supervise?\nEnter Employee code : ";
        int c;
        cin >> c;
        for (int i = 1; i <= s; i++)
        {
            if (c == m[i].code)
            {
                k = k + 1;
                m[i].code2 = sup;
                ref[k] = &m[i];
                break;
            }
        }
    }
    void delrefemp()
    {
        cout << "Which reference you want to delete?\nEnter Employee code : ";
        int c;
        cin >> c;
        for (int i = 1; i <= k; i++)
        {
            if (c == ref[i]->code)
            {
                ref[i]->code2 = 0;
                ref[i] = NULL;
                break;
            }
        }
    }
    void display()
    {
        employee::display();
        if (k != 0)
        {
            cout << "References :" << endl;
            for (int i = 1; i <= k; i++)
            {
                if (ref[i] != NULL)
                    cout << i << " : " << ref[i]->name << endl;
            }
        }
    }
    // void addref(employee e[], manager m[], int s2)
    // {
    //     for (int i = 0; i <= s2; i++)
    //     {
    //         if (e->code == m[i]->ref)
    //         {
    //             ref2 = &m[i];
    //         }
    //     }
    // }
};
void menu()
{
    cout << "Employee Management System\n1. add manager\n2. add employee\n3. display manager\n4. display employee\n5. add employref to manager\n6. Delete reference\n7.exit" << endl;
}
int main()
{
    int m = 0, n = 0, n2 = 0;
    employee person[20];
    manager person2[20];
    while (m != 7)
    {
        menu();
        cin >> m;
        switch (m)
        {
        case 1:
            n2 += 1;
            cout << "Manager : " << n2 << endl;
            person2[n2].addemployee();
            break;
        case 2:
            n += 1;
            cout << "Employee : " << n << endl;
            person[n].addemployee();
            break;
        case 3:
            int c;
            cout << "Which manager code :";
            cin >> c;
            for (int i = 1; i <= n2; i++)
            {
                if (c == person2[i].code)
                {
                    person2[i].display();
                    break;
                }
            }
            break;
        case 4:
            int c2;
            cout << "Which employee code :";
            cin >> c2;
            for (int i = 1; i <= n; i++)
            {
                if (c2 == person[i].code)
                {
                    person[i].display();
                    cout << "supervisor code : " << person[i].code2 << endl;
                    break;
                }
            }
            break;
        case 5:
            cout << "Which manager ?" << endl;
            int cc;
            cin >> cc;
            for (int i = 1; i <= n2; i++)
            {
                if (cc == person2[i].code)
                {
                    person2[i].addrefemp(person, n, cc);
                    break;
                }
            }
            break;
        case 6:
            cout << "Which manager ?" << endl;
            int ccw;
            cin >> ccw;
            for (int i = 1; i <= n2; i++)
            {
                if (cc == person2[i].code)
                {
                    person2[i].delrefemp();
                    break;
                }
            }
            break;
        case 7:
            break;
        }
    }
}
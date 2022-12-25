#include <iostream>
using namespace std;
class Department
{
public:
    string name;
    double ts;
    double tt;

public:
    // Department(string s, int t1, int t2)
    // {
    //     name = s;
    //     ts = t1;
    //     tt = t2;
    // }
    virtual double equipment_index() = 0;
    void Display()
    {
        cout << "Name :" << name << endl;
        cout << "Total Teachers = " << tt << endl;
        cout << "Total Students = " << ts << endl;
    }
};
class EEE : public Department
{
public:
    double tmc;

public:
    EEE(string s, double t, double stu, double m)
    {
        name = s;
        tt = t;
        ts = stu;
        tmc = m;
    }
    double equipment_index()
    {
        double index;
        try
        {
            if (ts == 0)
            {
                throw ts;
            }
            else
            {
                index = tmc / ts;
                return index;
            }
        }
        catch (double e)
        {
            cout << "Divide by zero Error ";
        }
        return 0;
    }
    void Display()
    {
        Department::Display();
        cout << "Total Machines = " << Total() << endl;
        cout << "Machine Index = " << equipment_index() << endl;
    }
    double Total()
    {
        return tmc;
    }
};
class CSE : public Department
{
public:
    double tc;
    double index;

public:
    CSE(string s, double t2, double stu2, double c)
    {
        name = s;
        tt = t2;
        ts = stu2;
        tc = c;
    }
    double equipment_index()
    {
        double index;
        try
        {
            if (ts == 0)
            {
                throw ts;
            }
            else
            {
                index = tc / ts;
                return index;
            }
        }
        catch (double e)
        {
            cout << "Divide by zero Error  v  ";
        }
        return 0;
    }
    void Display()
    {
        Department::Display();
        cout << "Total Computers = " << Total() << endl;
        cout << "Computer Index = " << equipment_index() << endl;
    }
    double Total()
    {
        return tc;
    }
};

class ECE : public Department
{
public:
    double tmc, tc;

public:
    ECE(string s, double t, double stu, double m, double c)
    {
        name = s;
        tt = t;
        ts = stu;
        tmc = m;
        tc = c;
    }
    double equipment_index()
    {
        double index;
        try
        {
            if (ts == 0)
            {
                throw ts;
            }
            else
            {
                index = (tmc + tc) / ts;
                return index;
            }
        }
        catch (double e)
        {
            cout << "Divide by zero Error ";
        }
        return 0;
    }
    void Display()
    {
        Department::Display();
        cout << "Total Machines = " << tmc << endl;
        cout << "Total Computers = " << tc << endl;
        cout << "Machine + Computer Index = " << equipment_index() << endl;
    }
    double Total()
    {
        return tmc + tc;
    }
};

int main()
{
    EEE eee("EEE", 50, 1000, 50);
    CSE cse("CSE", 30, 1200, 200);
    ECE ece("ECE", 30, 1200, 25, 100);
    eee.Display();
    cse.Display();
    ece.Display();
    cout << "Total equipments = " << eee.Total() + cse.Total() + ece.Total() << endl;
    cout << "End of Program" << endl;
}
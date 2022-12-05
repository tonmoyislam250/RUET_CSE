// PROGRAM: Bank Management system by OOP CPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;
string i, pass;
long double deposit;
const double annualRate = 0.20;
class General
{
private:
    long double belen, belen2;
    long double sumOfBal;
    double monthlyIn;
    double rate;

public:
    long double constructor(double bal, double inter);
    long double intCal(double b1, double in1);
    long double deposit(double a);
    long double withdraw(double b);
    double servCharges();
};

class Choices
{
private:
    string a, b, c;
    int in;
    int pick;
    char rawr;
    long double sum;

public:
    int showc();
    void loginc();
    void selectChoice();
    void display_account();
};

class Savings
{
private:
    string act;
    long double con;
    bool the;

public:
    string active();
    bool check();
    void printCheck();
};

class Newacc
{
private:
    string a1, a2;
    char n[100], age[100], ad[100];
    string p1, p2;
    double dep, hell;

public:
    void Reg();
    void Login();
    void Save();
    void Save2();
    void load();
    void Delete();
    double get_money();
};

class History
{
private:
    double depoSum, withSum;

public:
    void savingDepo(double a);
    void savingWith(double a);
    void dispTotalDepo();
    void dispTotalWith();
};

class History2
{
public:
    void dispStatDepo();
    void dispStatWith();
};

General gen;
Choices ch;
Newacc acc;
Savings save;
History his;
History2 his2;

int main()
{
    int x;
    char last;
    cout << "\t\t   ===================================\n";
    cout << "\t\t\tWelcome to my bank\n";
    cout << "\t\t\tThis is a program of banking\n";
    cout << "\t\t   ===================================\n";
START:
    cout << "\nPress Enter to reveal the Options >\n";
    getchar();
    x = ch.showc();
#ifdef _WIN32
    system("md accounts");
#endif
#ifdef linux
    system("mkdir -p ./accounts");
#endif
    switch (x)
    {
    case 1:
        cout << "You have selected to register a new account.\n";
        acc.Reg();
        goto START;
        break;
    case 2:
        cout << "You have selected to login into your account\n";
        acc.Login();
        break;
    case 3:
        cout << "You have proceeded to delete a record";
        acc.Delete();
        break;
    case 4:
        goto END;
        break;
    default:
        cout << "Sorry wrong input. Please try again.\n\n";
        acc.load();
        goto START;
        break;
    }
    acc.load();
    cout << "Continue Menu ?(Y/N)\n";
    cin >> last;

    if (last == 'Y' || last == 'y')
    {
        goto START;
    }
    else
    {
        EXIT_FAILURE;
        acc.load();
    }
END:
    cout << "\n\n\t\tThank you for Banking :D\n\n\n";
    return 0;
}

long double General::constructor(double bal, double inter)
{
    belen = intCal(bal, inter);
    return belen;
}
long double General::intCal(double b1, double in1)
{
    rate = (in1 / 12);
    monthlyIn = b1 * rate;
    sumOfBal = b1 + monthlyIn - servCharges();
    return sumOfBal;
}
long double General::deposit(double a)
{
    belen = acc.get_money() + a;
    his.savingDepo(a);
    return belen;
}
long double General::withdraw(double b)
{
    belen2 = acc.get_money() - b;
    return belen2;
}
double General::servCharges()
{
    ifstream ka;
    ka.open(("./accounts/" + i + "D-history.txt").c_str());
    double x[1000];
    string y[1000];
    int a = 0;
    int man = 0;
    double total = 0;
    while (!ka.eof())
    {
        ka >> x[a];
        ka >> y[a];
        a++;
        if (a > 4)
        {
            ++man;
        }
    }
    --a;
    --man;
    total = (a * 0.1) + man + (5 * 12);
    ka.close();
    return total;
}

int Choices::showc()
{
    cout << "1. Create a new account\n";
    cout << "2. Log into your account\n";
    cout << "3. Delete an account\n";
    cout << "4. Exit this programe \n\n Enter your choice: ";
    cin >> std::ws;
    cin >> in;
    return in;
}
void Choices::loginc()
{
    cout << "===================================\n";
    cout << "Welcome user  " << i << "!!!\n";
    cout << "===================================\n\n";
    cout << "What do you want? :\n\n";
    cout << "1. Withdraw Money\n";
    cout << "2. Deposit Money\n";
    cout << "3. Check Account \n";
    cout << "4. Monthly Statistics \n";
    cout << "5. LOG OUT\n\n";
    cout << "Enter your option : ";
}
void Choices::display_account()
{
    ifstream k;
    k.open(("./accounts/" + i + ".txt").c_str());
    getline(k, i);
    getline(k, pass);
    getline(k, a);
    getline(k, b);
    getline(k, c);
    cout << "Username : " << i << endl;
    cout << "Full Name : " << a << endl;
    cout << "Age : " << b << endl;
    cout << "Address : " << c << endl;
}

void Choices::selectChoice()
{
    double kaka;
BEGIN:
    loginc();
    cin >> pick;
    switch (pick)
    {
    case 1:
        cout << "\nWithdrawing Money\n\n";
        if (save.check() == true)
        {
            save.printCheck();
            acc.load();
            goto BEGIN;
        }
        cout << "Enter the amount of money to withdraw\n\n";
        cout << "Taka :  ";
        cin >> kaka;
        sum = gen.withdraw(kaka);
        if (sum < 0)
        {
            cout << "\n\n\t\tBalance is less than 100 taka!\n\n";
            acc.load();
            goto BEGIN;
        }
        his.savingWith(kaka);
        deposit = sum;
        acc.Save2();
        cout << "\nThe withdraw was Successfull" << endl;
        acc.load();
        goto BEGIN;
        break;
    case 2:
        cout << "Depositing Money\n\n";
        cout << "Enter the amount of money to Deposit\n\n";
        cout << "Taka : ";
        cin >> kaka;
        sum = gen.deposit(kaka);
        deposit = sum;
        acc.Save2();
        cout << "\nSuccessfully Deposited" << endl;
        acc.load();
        goto BEGIN;
        break;

    case 3:
        cout << "\n***Account Details***\n\n";
        ch.display_account();
        kaka = acc.get_money();
        cout << fixed << setprecision(2);
        cout << "Balance : " << kaka << "taka" << endl;
        acc.load();
        goto BEGIN;
        break;
    case 4:
        his2.dispStatWith();
        his2.dispStatDepo();
        his.dispTotalDepo();
        his.dispTotalWith();
        cout << "\n\n";
        acc.load();
        goto BEGIN;
        break;
    case 5:
        cout << "\n\n\t\tThank you for working with us\n\n";
        break;
    default:
        cout << "\nSorry, Wrong input!\n\n";
        acc.load();
        goto BEGIN;
        break;
    }

POPO:
    cout << "\n\nIs it the end of year? (Y/N)\n";
    cin >> rawr;
    if (rawr == 'Y' || rawr == 'y')
    {
        ifstream l;
        double rate2, monthlyIn2;
        double pe;
        pe = acc.get_money();
        cout << "\n\nAnnual Rate of Interest";
        deposit = gen.constructor(pe, annualRate);
        acc.Save2();
        rate2 = (annualRate / 12);
        monthlyIn2 = pe * rate2;
        cout << fixed << setprecision(2);
        cout << "\nTotal Interest rate = " << monthlyIn2 << "Taka";
        cout << "\nTotal Service charge = " << gen.servCharges() << "Taka";
        cout << "\nTotal Balance after a year is :\n";
        cout << "taka " << deposit;
        cout << "\n\n";
    }
    else if (rawr == 'N' || rawr == 'n')
    {
        cout << "\n\nTHANK YOU! :D\n";
    }

    else
    {
        cout << "Sorry, Wrong Input!";
        goto POPO;
    }
}

string Savings::active()
{
    con = acc.get_money();

    if (con < 100.00)
    {
        act = "INACTIVE";
    }
    else if (con >= 100.00)
    {
        act = "ACTIVE";
    }

    return act;
}
bool Savings::check()
{
    string p;

    p = active();

    if (p == "INACTIVE")
    {
        the = true;
    }
    else if (p == "ACTIVE")
    {
        the = false;
    }

    return the;
}

void Savings::printCheck()
{
    cout << "Unsuccessful withdraw \n";
    cout << "Your account is inactive \n";
    cout << "Check balance and deposit to make balance more than 100 taka \n";
}

void Newacc::Reg()
{
    bool open = false;
    do
    {
        cout << "Enter your name: ";
        cin.ignore();
        cin.getline(n, 100);
        cout << "Enter your age: ";
        cin.getline(age, 100);
        cout << "Enter your Address: ";
        cin.getline(ad, 100);
        cout << "Entet your ID :  ";
        cin >> std::ws;
        getline(cin, a1);
        ifstream file1;
        file1.open(("./accounts/" + a1 + ".txt").c_str());
        if (!file1)
        {
            open = true;
        }
        else if (file1)
        {
            cout << "\n\nId name has been used by other user";
            cout << "\nPlease try again\n\n\n";
            open = false;
            load();
        }
        file1.close();
    } while (open != true);
    cout << "Insert your password :  ";
    cin >> std::ws;
    getline(cin, p1);
    cout << endl;
    cout << "Insert your deposit\n";
    cout << "(minium 100 taka)\n";
    cout << "\n\nDeposit ";

    while (dep <= 100.00)
    {
        cin >> dep;

        if (dep >= 100.00)
        {
            Save();
            break;
        }
        else
        {
            cout << "\n\n Not enough money for deposit\n Deposit :\n";
        }
    }
    cout << "\n\n\t\tRegistration successful :D\n\n";
    load();
}
void Newacc::Delete()
{
    char q;
    do
    {
    LOGIN:
        cout << "\nRemoving Record....\n";
        cout << "\n\nEnter your id : ";
        cin >> i;
        cout << "Enter your pass : ";
        cin >> pass;
        cout << endl;
        ifstream log;
        log.open(("./accounts/" + i + ".txt").c_str());
        log >> a2 >> p2;
        hell = acc.get_money();
        if (i == a2 && pass == p2 && hell == 0)
        {
            remove(("./accounts/" + i + ".txt").c_str());
            cout << "Personal Data has been Deleted" << endl;
            remove(("./accounts/" + i + "D-history.txt").c_str());
            cout << "Deposit History has been Deleted" << endl;
            remove(("./accounts/" + i + "W-history.txt").c_str());
            cout << "Full Record Removed....\n";
        }
        else if (hell != 0)
            cout << "Balance isn't' zero can't delete account" << endl;
        else
        {
            cout << "Id or pass is invalid\nOr that account doesn't exists";
            cout << "Try again (Y/N)\n";
            cin >> q;
            if (q == 'Y' || q == 'y')
            {
                goto LOGIN;
            }
            else
            {
                goto OUT;
            }
        }
    } while (i != a2 && pass != p2);
OUT:;
    load();
}
void Newacc::Login()
{
    char q;
    do
    {
    LOGIN:
        cout << "\n***Login Page***" << endl;
        cout << "\n\nEnter your id : ";
        cin >> i;
        cout << "Enter your password : ";
        cin >> pass;
        cout << endl;
        ifstream log;
        log.open(("./accounts/" + i + ".txt").c_str());
        log >> a2 >> p2;
        if (i == a2 && pass == p2)
        {
            cout << "Logged in\n";
            load();
            ch.selectChoice();
        }
        else
        {
            cout << "Id or pass is invalid \nOr the accound doesn't exists in accounts folder\n";
            cout << "Try again (Y/N)\n";
            cin >> q;
            if (q == 'Y' || q == 'y')
            {
                goto LOGIN;
            }
            else
            {
                goto OUT;
            }
        }
    } while (i != a2 && pass != p2);
OUT:;
    load();
}

void Newacc::Save()
{
    ofstream saving;
    saving.open(("./accounts/" + a1 + ".txt").c_str());
    saving << a1 << endl
           << p1 << endl
           << n << endl
           << age << endl
           << ad << endl
           << dep;
    saving.close();
    time_t t = time(0);
    struct tm *now = localtime(&t);
    ofstream w;
    w.open(("./accounts/" + a1 + "D-history.txt").c_str());
    w << dep << " " << setw(2) << setfill('0') << now->tm_mday << '.'
      << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
      << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;
    w.close();
}
void Newacc::Save2()
{
    string a, b, c;
    ifstream myFile;
    myFile.open(("./accounts/" + i + ".txt").c_str());
    getline(myFile, i);
    getline(myFile, pass);
    getline(myFile, a);
    getline(myFile, b);
    getline(myFile, c);
    ofstream saving2;
    saving2.open(("./accounts/" + i + ".txt").c_str());
    saving2 << i << endl
            << pass << endl
            << a << endl
            << b << endl
            << c << endl
            << deposit;
}

void Newacc::load()
{
#ifdef _WIN32
    system("pause");
    system("cls");
#endif
#ifdef linux
    system("bash -c 'read -n1 -r enter'");
    system("clear");
#endif
}

double Newacc::get_money()
{
    ifstream myFile;
    string a, b, c, pa;
    myFile.open(("./accounts/" + i + ".txt").c_str());
    getline(myFile, i);
    getline(myFile, pa);
    getline(myFile, a);
    getline(myFile, b);
    getline(myFile, c);
    myFile >> dep;
    myFile.close();
    return dep;
}

void History::savingDepo(double a)
{
    ofstream file;
    ifstream myFile;
    double look[1000], eye;
    int tot = 0;
    string date[1000];
    time_t t = time(0);
    struct tm *now = localtime(&t);
    myFile.open(("./accounts/" + i + "D-history.txt").c_str());

    if (!myFile)
    {
        ofstream wt;
        wt.open(("./accounts/" + i + "D-history.txt").c_str());
        wt.close();
        myFile.open(("./accounts/" + i + "D-history.txt").c_str());
    }
    while (!myFile.eof())
    {
        myFile >> eye;
        getline(myFile, date[tot]);
        look[tot] = eye;
        tot++;
    }
    myFile.close();
    file.open(("./accounts/" + i + "D-history.txt").c_str());
    for (int i = 0; i < tot - 1; i++)
    {
        file << look[i] << date[i] << endl;
    }
    file << a << " " << setw(2) << setfill('0') << now->tm_mday << '.'
         << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
         << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;
    file.close();
}

void History::savingWith(double a)
{
    ofstream file;
    ifstream myFile;
    time_t t = time(0); // get time now
    struct tm *now = localtime(&t);
    string date[1000];
    double look[100], eye;
    int tot = 0;
    myFile.open(("./accounts/" + i + "W-history.txt").c_str());
    if (!myFile)
    {
        ofstream wt;
        wt.open(("./accounts/" + i + "W-history.txt").c_str());
        wt.close();
        myFile.open(("./accounts/" + i + "W-history.txt").c_str());
    }

    while (!myFile.eof())
    {
        myFile >> eye;
        getline(myFile, date[tot]);
        look[tot] = eye;
        tot++;
    }

    myFile.close();

    file.open(("./accounts/" + i + "W-history.txt").c_str());
    for (int i = 0; i < tot - 1; i++)
    {
        file << look[i] << date[i] << endl;
    }

    file << a << " " << setw(2) << setfill('0') << now->tm_mday << '.'
         << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
         << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;
    file.close();
}
void History::dispTotalDepo()
{
    ifstream file;
    string an;
    double TotalDepo = 0;
    file.open(("./accounts/" + i + "D-history.txt").c_str());
    while (!file.eof())
    {
        file >> depoSum >> an;
        TotalDepo = TotalDepo + depoSum;
    }

    TotalDepo = TotalDepo - depoSum;

    cout << fixed << setprecision(2);
    cout << "\nTotal Deposit of this year = " << TotalDepo << "Taka";

    file.close();
}
void History::dispTotalWith()
{
    ifstream file;
    string an;
    double TotalWith = 0;
    file.open(("./accounts/" + i + "W-history.txt").c_str());
    if (!file)
    {
        cout << "\nWithdraw has not been done!" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> withSum >> an;
            TotalWith = TotalWith + withSum;
        }

        TotalWith = TotalWith - withSum;

        cout << fixed << setprecision(2);
        cout << "\nTotal withdraw of this year = " << TotalWith << "Taka";

        file.close();
    }
}

void History2::dispStatDepo()
{
    ifstream ka;
    ka.open(("./accounts/" + i + "D-history.txt").c_str());
    double x[1000];
    string y[1000];
    int a = 0;
    while (!ka.eof())
    {
        ka >> x[a];
        ka >> y[a];
        a++;
    }
    ka.close();
    string month[1000];
    int tryDate[1000];
    int jan[1000], feb[1000], mar[1000], apr[1000], may[1000], jun[1000], jul[1000], aug[1000], sep[1000];
    int oct[1000], nov[1000], dis[1000];

    cout << "\n\n========================================\n";
    cout << "STATISTIC FOR DEPOSIT FOR THE WHOLE YEAR\n";
    cout << "========================================\n\n\n";
    cout << "JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DIS\n\n";
    for (int i = 0; i < a - 1; i++)
    {
        month[i] += y[i][3];
        month[i] += y[i][4];
        tryDate[i] = atoi((month[i]).c_str());
        switch (tryDate[i])
        {
        case 1:
            jan[i] = x[i];
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 2:
            jan[i] = 0;
            feb[i] = x[i];
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 3:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = x[i];
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 4:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = x[i];
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 5:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = x[i];
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 6:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = x[i];
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 7:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = x[i];
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 8:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = x[i];
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 9:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = x[i];
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 10:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = x[i];
            nov[i] = 0;
            dis[i] = 0;
            break;
        case 11:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = x[i];
            dis[i] = 0;
            break;
        case 12:
            jan[i] = 0;
            feb[i] = 0;
            mar[i] = 0;
            apr[i] = 0;
            may[i] = 0;
            jun[i] = 0;
            jul[i] = 0;
            aug[i] = 0;
            sep[i] = 0;
            oct[i] = 0;
            nov[i] = 0;
            dis[i] = x[i];
            break;
        }
        cout << setw(3) << setfill('0');
        cout << jan[i] << "   " << setw(3) << setfill('0') << feb[i] << "   " << setw(3) << setfill('0') << mar[i] << "   " << setw(3) << setfill('0') << apr[i] << "   " << setw(3) << setfill('0') << may[i] << "   ";
        cout << setw(3) << setfill('0') << jun[i] << "   " << setw(3) << setfill('0') << jul[i] << "   " << setw(3) << setfill('0') << aug[i] << "   " << setw(3) << setfill('0') << sep[i] << "   " << setw(3) << setfill('0') << oct[i] << "   ";
        cout << setw(3) << setfill('0') << nov[i] << "   " << setw(3) << setfill('0') << dis[i] << endl
             << endl;
    }

    cout << "\nFirst Deposit = " << fixed << setprecision(2) << x[0] << " Taka";
}
void History2::dispStatWith()
{
    ifstream ka;

    ka.open(("./accounts/" + i + "W-history.txt").c_str());
    double x[1000];
    string y[1000];
    int a = 0;
    if (!ka)
    {
        cout << "Please withdraw some money First" << endl;
    }
    else
    {
        while (!ka.eof())
        {
            ka >> x[a];
            ka >> y[a];
            a++;
        }
        ka.close();
        string month[1000];
        int tryDate[1000];
        int jan[1000], feb[1000], mar[1000], apr[1000], may[1000], jun[1000], jul[1000], aug[1000], sep[1000];
        int oct[1000], nov[1000], dis[1000];

        cout << "=========================================\n";
        cout << "STATISTIC FOR WITHDRAW FOR THE WHOLE YEAR\n";
        cout << "=========================================\n\n";
        cout << "JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DIS\n\n";
        for (int i = 0; i < a - 1; i++)
        {
            month[i] += y[i][3];
            month[i] += y[i][4];
            tryDate[i] = atoi((month[i]).c_str());
            switch (tryDate[i])
            {
            case 1:
                jan[i] = x[i];
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 2:
                jan[i] = 0;
                feb[i] = x[i];
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 3:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = x[i];
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 4:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = x[i];
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 5:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = x[i];
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 6:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = x[i];
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 7:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = x[i];
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 8:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = x[i];
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 9:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = x[i];
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 10:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = x[i];
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 11:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = x[i];
                dis[i] = 0;
                break;
            case 12:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = x[i];
                break;
            }
            cout << setw(3) << setfill('0');
            cout << jan[i] << "   " << setw(3) << setfill('0') << feb[i] << "   " << setw(3) << setfill('0') << mar[i] << "   " << setw(3) << setfill('0') << apr[i] << "   " << setw(3) << setfill('0') << may[i] << "   ";
            cout << setw(3) << setfill('0') << jun[i] << "   " << setw(3) << setfill('0') << jul[i] << "   " << setw(3) << setfill('0') << aug[i] << "   " << setw(3) << setfill('0') << sep[i] << "   " << setw(3) << setfill('0') << oct[i] << "   ";
            cout << setw(3) << setfill('0') << nov[i] << "   " << setw(3) << setfill('0') << dis[i] << endl
                 << endl;
        }
    }
}
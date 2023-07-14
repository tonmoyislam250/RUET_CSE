#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
int qq = 0, space = 0, aa = 0, q[2], i = 0;
bool isPrime(int x)
{
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
void berify(int n, int choice)
{
    if (isPrime(n))
    {
        q[i] = n;
        i++;
        cout << "p" << i << " : " << n << endl;
    }
    else if (choice == 2)
        cout << n << " is not prime" << endl;
}
int extend(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extend(b, a % b, x1, y1);
    //	cout << endl;
    //	cout << "x1: " << x1 << " y1: " << y1 << endl;
    //	cout << "a: " << a << " b: " << b << endl;
    x = y1;
    y = x1 - y1 * (a / b);
    //	cout << "x: " << x << " y: " << y << endl;
    return d;
}
bool coprime(int a, int b)
{
    if (gcd(a, b) == 1)
        return true;
    else
        return false;
}
int modE(int b, int e, int ms)
{
    int result = 1;
    while (e > 0)
    {
        if (e % 2 == 1)
            result = (result * b) % ms;
        b = (b * b) % ms;
        e = e / 2;
    }
    return result;
}

void chartoint(string msg, int msg2[])
{
    for (char c : msg)
    {
        if (isalpha(c))
            msg2[qq++] = tolower(c) - 'a';
        if (c == ' ')
            space++;
    }
}

int main()
{
    int x, y;
    srand(time(NULL));
    int n, choice = 0;
    cout << "1. random\n2. own\n";
    cin >> choice;
    while (1)
    {
        if (choice == 2)
        {
            cin >> n;
            berify(n, choice);
            if (i == 2)
                break;
        }
        else
        {
            n = 10 + rand() % 99;
            berify(n, choice);
            if (i == 2)
                break;
        }
    }
    cout << "Encryption : " << endl;
    cout << "n : " << q[0] * q[1] << endl;
    int choi = 7, m = 2;
    int key = (q[0] - 1) * (q[1] - 1);
    int kk = q[0] * q[1];
    cout << "1. random\n2. own\n";
    cin >> choi;
    while (1)
    {
        if (choi == 2)
            cin >> m;
        else
            m++;
        if (coprime(key, m))
        {
            if (key > m)
            {
                cout << "e : " << m << endl;
                break;
            }
        }
        else if (!coprime(key, m) && choi == 2)
            cout << m << " isn't coprime with " << key << endl;
    }
    int dec = extend(m, key, x, y);
    dec++;
    while (x < 0)
        x = x + key;
    cout << "Decryption key : " << x << endl;
    cout << "1. encryption\n2. decryption" << endl;
    int choice2;
    cin >> choice2;
    if (choice2 == 1)
    {
        cout << "enter msg : ";
        string msg;
        cin.ignore();
        getline(cin, msg);
        int msg2[msg.size()];
        chartoint(msg, msg2);
        // cout << msg.size() << " " << space << endl;
        cout << "Encrypted message : " << endl;
        for (int i = msg.size() - space - 1; i >= 0; i -= 2)
        {
            int sum = 0;
            // cout << msg2[i] << msg2[i - 1] << endl;
            for (int ii = 0, pp = 0; ii < 2 && pp <= 2; ii++, pp += 2)
                sum += msg2[i - ii] * pow(10, pp);
            // cout << "sum : " << sum << endl;
            int cryted = modE(sum, m, kk);
        }
    }
    else
    {
        int size;
        cout << "how many vlocks : ";
        cin >> size;
        while (size--)
        {
            int block;
            cin >> block;
            int cryted = modE(block, x, kk);
            cout << cryted << " ";
        }
    }
    return 0;
}
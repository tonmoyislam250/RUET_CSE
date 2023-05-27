#include <iostream>
#include <vector>
using namespace std;
void sieveE(int a)
{
    vector<int> p(a + 1, true);
    fill(p.begin(), p.end(), 0);
    for (int i = 2; i * i <= a; i++)
    {
        if (p[i] == 0)
        {
            for (int j = i * i; j <= a; j += i)
                p[j] = 1;
        }
    }
    for (int i = 2; i <= a; i++)
        if (p[i] == 0)
            cout << i << " ";
}
int main()
{
    int a;
    cout << "Enter Number n: ";
    cin >> a;
    cout << "Prime numbers upto " << a << " are: " << endl;
    sieveE(a);
    return 0;
}
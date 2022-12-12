#include <iostream>
#include <fstream>
using namespace std;
struct node
{
    int data;
    node *ll;
    node *rr;
};
int main()
{
    int LL[50], DATA[50], RL[50];
    ifstream mac;
    mac.open("store.txt");
    int i = 1;
    while (mac >> LL[i])
    {
        char U;
        mac >> U;
        DATA[i] = int(U);
        mac >> RL[i];
        cout << LL[i] << " " << char(DATA[i]) << " " << RL[i] << endl;
        i++;
    }
    struct node ax[i];
    for (int m = 1; m <= i - 1; m++)
    {
        cout << "Node: " << m << " " << char(DATA[m]) << " " << &ax[m] << endl;
        ax[m].data = DATA[m];
        ax[m].ll = &ax[LL[m]];
        ax[m].rr = &ax[RL[m]];
    }
    for (int m = 1; m < i; m++)
    {
        cout << ax[m].ll << " " << LL[m] << "      " << char(ax[m].data) << "     " << RL[m] << " " << ax[m].rr << endl;
    }
}
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void solve()
{
    char w[10];
    char txt[100];
    char ch[100];
    gets(w);
    gets(txt);
    ofstream file;
    int count = 0;
    file.open("out.txt");
    for (int i = 0; i < strlen(txt); i++)
        file << txt[i];
    file.close();
    ifstream file2;
    file2.open("out.txt");
    while (file2 >> ch)
    {
        file2 >> ch;
        cout << ch;
        if (strcmp(ch, w) == 0)
        {
            count++;
        }
    }
    file2.close();
}
int main()
{
    solve();
}
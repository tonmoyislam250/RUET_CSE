#include <iostream>
using namespace std;
int main()
{
    string i;
    int ax[5] = {10, 20, 60, 40, 30};
    cout << "Enter Index :";
    getline(cin, i);
    try
    {
        if (stoi(i) < 0 || stoi(i) > 4)
        {
            throw "Index out of Range";
        }
        else if (stoi(i) > 0 && stoi(i) <= 4)
        {
            throw stoi(i);
        }
    }
    catch (char const *ex)
    {
        cout << ex << endl;
    }
    catch (int i)
    {
        cout << "a[" << i << "]=" << ax[i] << endl;
    }
    catch (...)
    {
        cout << "Your index is not an integer" << endl;
    }
}
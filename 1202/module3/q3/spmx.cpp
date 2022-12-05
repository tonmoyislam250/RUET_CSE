#include <iostream>
using namespace std;
class Sp
{
private:
    int k = 0;
    int n, m;
    int s[100][3], z[100][100];

public:
    void get_data_display(int a, int b)
    {
        n = a;
        m = b;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> z[i][j];
        cout << "Displaying Main Matrix " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << z[i][j] << " ";
            cout << endl;
        }
    }
    void sparsing()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (z[i][j] != 0)
                {
                    k++;
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = z[i][j];
                }
            }
        }
        s[0][0] = n;
        s[0][1] = m;
        s[0][2] = k;
    }
    void display_sparsing()
    {
        cout << "Displaying Sparse Matrix Table...." << endl;
        cout << "Rows Columns Elements" << endl;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Sp test;
    int x, y;
    cout << "Enter Row and Column Size (max: 100)" << endl;
    cin >> x >> y;
    cout << "Enter The Main Matrix elements: " << endl;
    test.get_data_display(x, y);
    test.sparsing();
    test.display_sparsing();
}

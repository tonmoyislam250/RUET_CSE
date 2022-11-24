#include <iostream>
using namespace std;
class TEST
{
private:
    int x;
    int y;
    static int z;

public:
    TEST() //(i)
    {
        x = 0;
        y = 0;
        z = 0;
    }
    TEST(int a, int b) //(ii)
    {
        x = a;
        y = b;
        z++;
    }
    void set_data(int a, int b) //(v)
    {
        x = a;
        y = b;
        z++;
    }
    void copy_data(TEST &test1) //(iii)
    {
        x = test1.x;
        y = test1.y;
        z++;
    }
    void display_data()
    {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
        cout << "z : " << z << endl;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    int get_z()
    {
        return z;
    }
};
int TEST::z;
int main()
{
    int index = 0, sum = 0;
    TEST test[5]; //(viii)
    test[1].set_data(5, 56);
    test[2].copy_data(test[1]); ///(iii)
    test[3].set_data(21, 70);
    test[4].set_data(8, 9);
    test[5].set_data(3, 5);
    cout << "Total number of Objects are " << test[5].get_z() << endl; //(iv) && (vi)
    for (int i = 1; i <= 5; i++)
    {
        sum = sum + test[i].get_x();
    }
    cout << "The sum of the values of x is = " << sum << endl; //(ix)
    int max = test[1].get_y();
    for (int i = 1; i <= 5; i++)
    {
        if (test[i].get_y() > max)
        {
            max = test[i].get_y();
            index = i;
        }
    }
    cout << "The " << index << " number Object has the max value of y" << endl; //(x)
    return 0;
}
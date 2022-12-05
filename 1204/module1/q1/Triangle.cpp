// PROGRAM: Get area and Perimeter of triangle by OOP cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Triangle
{
private:
    float a, b, c;

public:
    Triangle()
    {
        a = 1;
        b = 1;
        c = 1;
    }
    void triangle_set(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }
    void triangle_get()
    {
        cout << "a = " << a << "\nb = " << b << "\nc = " << c << endl;
    }
    void triangle_peri()
    {
        float s;
        s = (a + b + c);
        if (a < b + c && b < c + a && c < a + b)
        {
            cout << "The Perimeter of Triangle is " << s << endl;
        }
    }
    void triangle_area()
    {
        float A, s;
        s = (a + b + c) / 2;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        if (a < b + c && b < c + a && c < a + b)
        {
            cout << setprecision(2) << "The Area of Triangle is " << A << endl;
        }
        else
        {
            cout << "Triangle is Not possible" << endl;
        }
    }
};
int main()
{
    float m, n, o;
    cout << "Input Three sides of the Triangle: ";
    cin >> m >> n >> o;
    Triangle tri;
    tri.triangle_set(m, n, o);
    tri.triangle_get();
    tri.triangle_peri();
    tri.triangle_area();
    return 0;
}
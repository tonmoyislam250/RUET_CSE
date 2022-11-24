#include <iostream>
#include <iomanip>
using namespace std;
class Circuit
{
private:
    float real, img;

public:
    Circuit(float r = 0, float i = 0)
    {
        real = r;
        img = i;
    }
    Circuit operator+(Circuit const &next)
    {
        Circuit prev;
        prev.real = real + next.real;
        prev.img = img + next.img;
        return prev;
    }
    Circuit operator-(Circuit const &next)
    {
        Circuit prev;
        prev.real = real - next.real;
        prev.img = img - next.img;
        return prev;
    }
    Circuit operator*(Circuit const &next)
    {
        Circuit prev;
        prev.real = real * next.real - img * next.img;
        prev.img = real * next.img + img * next.real;
        return prev;
    }
    Circuit operator/(Circuit const &next)
    {
        Circuit prev;
        prev.real = (real * next.real + img * next.img) / ((next.real * next.real + next.img * next.img));
        prev.img = (img * next.real - real * next.img) / ((next.real * next.real) + (next.img * next.img));
        return prev;
    }
    void print()
    {
        cout << "The Current of The Circuit is ";
        cout << real << " + i"
             << "(" << img << ")" << endl;
    }
};

int main()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
    Circuit z1(3, 4), z2(4, -3), z3(0, 6), z4(100, 50);
    Circuit result, eq;
    eq = ((z1 * z2 * z3) / (z1 * z2 + z2 * z3 + z3 * z1));
    result = z4 / ((z1 * z2 * z3) / (z1 * z2 + z2 * z3 + z3 * z1));
    eq.print();
    result.print();
}
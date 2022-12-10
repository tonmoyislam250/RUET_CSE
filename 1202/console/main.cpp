#include "array.cpp"
using namespace std;
int main()
{
    queueing Q;
    stacking S;
    int tsize, ttime;
    int time = 0, size = 0;
    cin >> tsize >> ttime;
    while (tsize--)
    {
        int x, t;
        cin >> x >> t;
        Q.enqueue(x);
    }
}
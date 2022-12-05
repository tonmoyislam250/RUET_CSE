#include <iostream>

using namespace std;

class SearchMethods
{
private:
    int arr[1000], n, flag = 0;

public:
    void setArray()
    {
        cout << "Enter the size of array:";
        cin >> n;
        cout << "Enter the elements of the array in sorted manner: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    int linearSearch(int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    };
    int binarySearch(int x)
    {
        int l = 0, h = n - 1, mid;

        while (l <= h)
        {
            mid = (l + n) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] < x)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    };
};

int main()
{
    int x;
    SearchMethods l;
    l.setArray();
    cout << "Enter the number to find: ";
    cin >> x;
    int r1 = l.linearSearch(x);
    int r2 = l.binarySearch(x + 1);
    if (r1 != -1)
        cout << "Index from linear search is " << r1 << endl;
    if (r2 != -1)
        cout << "Index from binary search is " << r2 << endl;
}
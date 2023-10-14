#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long count1 = 1, count2 = 0;
long long binarySearch(long long size, long long target)
{
    long long left = 0;
    long long right = size - 1;
    long long arr[size];
    string file = "search" + to_string(size) + ".txt";
    ifstream input(file);
    for (long long i = 0; i < size; i++)
        input >> arr[i];
    input.close();
    sort(arr, arr + size);
    while (left <= right)
    {
        count2++;
        long long mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else if (arr[mid] > target)
            right = mid - 1;
    }
    return -1;
}
long long linearSearch(long long size, long long target)
{
    string file = "search" + to_string(size) + ".txt";
    ifstream input(file);
    auto start = std::chrono::high_resolution_clock::now();
    for (long long i = 0; i < size; i++)
    {
        int a;
        input >> a;
        count1++;
        if (a == target)
            return i;
    }
    input.close();
    auto stop = std::chrono::high_resolution_clock::now();
    return -1;
}

int main()
{
    srand(time(0));
    system("cls");
    long long n, target;
    cout << "How many Numbers : ";
    cin >> n;
    cout << "Enter the target: ";
    cin >> target;
    long long result = linearSearch(n, target);
    long long result2 = binarySearch(n, target);
    if (result != -1 || result2 != -1)
    {
        cout << "Linear Search" << endl;
        cout << "Key: " << result << endl;
        cout << "Value: " << target << endl;
        cout << "Steps: " << count1 << endl;
        cout << "######################" << endl;
        cout << "Binary Search" << endl;
        cout << "Key: " << result2 << endl;
        cout << "Value: " << target << endl;
        cout << "Steps: " << count2 << endl;
    }
    else
        cout << "Element not found in the array." << std::endl;

    return 0;
}

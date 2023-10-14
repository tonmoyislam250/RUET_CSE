#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    long long n;
    cout << "How many Numbers : ";
    cin >> n;
    string file = "search" + to_string(n) + ".txt";
    ofstream input(file);
    for (long long i = 0; i < n; i++)
        input << rand() << " ";
    input.close();
}
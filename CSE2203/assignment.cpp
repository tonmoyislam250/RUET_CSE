#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
double calculateCombination(double n, double r, bool h)
{
    double result = 1;
    for (int i = 1; i <= r; ++i)
    {
        if (h == true)
            result *= (n - i + 1) / i;
        else if (h == false)
            result *= (n + i - 1) / i;
    }
    return result;
}

void NewtonForward(int x, int n, long long ys[], int xs[], int h)
{
    long long sum = ys[0];
    cout << "x   ";
    for (int i = 0; i < n; i++)
        cout << xs[i] << " ";
    cout << endl;
    cout << "y   ";
    long long ys1[n];
    for (int i = 0; i < n; i++)
    {
        ys1[i] = ys[i];
        cout << ys1[i] << " ";
    }

    cout << endl;
    for (int j = 0; j < n - 1; j++)
    {
        cout << "\u0394" << j + 1 << "y  ";
        for (int i = 0; i < n - (j + 1); i++)
        {
            cout << ys1[i + 1] - ys1[i] << " ";
            ys1[i] = ys1[i + 1] - ys1[i];
        }
        cout << endl;
        double p = (x - xs[0]) / h;
        sum += (calculateCombination(p, j + 1, true) * ys1[0]);
    }
    cout << "The Answer is: " << sum << endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    ifstream file("World_population(1955-2020).csv");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    const int MAX_SIZE = 1000;
    int years[MAX_SIZE];
    long long populations[MAX_SIZE];
    string line, temp;
    getline(file, line);
    int count = 0;
    while (getline(file, line) && count < MAX_SIZE)
    {
        stringstream ss(line);
        getline(ss, temp, ',');
        years[count] = stoi(temp);
        getline(ss, temp, ',');
        populations[count] = stoll(temp);
        count++;
    }
    file.close();
    if (count == 0)
    {
        cerr << "Error: No data found in the file." << endl;
        return 1;
    }
    cout << "Existing data:" << endl;
    for (int i = 0; i < count; ++i)
        cout << years[i] << "\t" << populations[i] << endl;

    int h = years[1] - years[0];
    int lastYear = years[count - 1];
    cout << "\nProjected populations for the next ten years:" << endl;
    for (int i = 1; i <= 2; ++i)
    {
        int nextYear = lastYear + i * h;
        cout << nextYear << "\t"
             << "Projected Population" << endl;
        NewtonForward(nextYear, count, populations, years, h);
    }
    return 0;
}
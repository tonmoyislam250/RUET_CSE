#include <iostream>
#include <fstream>
#include <random>
using namespace std;

struct Point
{
    int x, y;
};

void generatePointsToFile(int numPoints)
{
    string file = to_string(numPoints) + ".txt";
    ofstream outputFile(file);
    if (!outputFile.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000);

    for (int i = 0; i < numPoints; i++)
    {
        Point p;
        p.x = distrib(gen);
        p.y = distrib(gen);
        outputFile << p.x << " " << p.y << endl;
    }

    outputFile.close();
    cout << "Generated " << numPoints << " points and saved them to input.txt" << endl;
}

int main()
{
    int numPoints;
    cout << "Enter the number of points to generate: ";
    cin >> numPoints;
    generatePointsToFile(numPoints);
    return 0;
}

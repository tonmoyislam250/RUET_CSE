#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

struct Point
{
    int x, y;
};

int findSide(Point a, Point b, Point p)
{
    int val = (p.y - a.y) * (b.x - a.x) - (b.y - a.y) * (p.x - a.x);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

void quickHull(vector<Point> &points, Point a, Point b, int side, vector<Point> &hull)
{
    int ind = -1;
    int maxDist = 0;
    for (int i = 0; i < points.size(); i++)
    {
        int temp = findSide(a, b, points[i]);
        if (temp == side)
        {
            int distance = abs((points[i].y - a.y) * (b.x - a.x) - (b.y - a.y) * (points[i].x - a.x));
            if (distance > maxDist)
            {
                ind = i;
                maxDist = distance;
            }
        }
    }
    if (ind == -1)
    {
        hull.push_back(a);
        hull.push_back(b);
        return;
    }
    quickHull(points, points[ind], a, -findSide(points[ind], a, b), hull);
    quickHull(points, points[ind], b, -findSide(points[ind], b, a), hull);
}

void convexHullQuick(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
    {
        cout << "Convex Hull not possible with less than 3 points." << endl;
        return;
    }

    vector<Point> hull;
    int minX = 0, maxX = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[minX].x)
            minX = i;
        if (points[i].x > points[maxX].x)
            maxX = i;
    }

    quickHull(points, points[minX], points[maxX], 1, hull);
    quickHull(points, points[minX], points[maxX], -1, hull);

    cout << "Convex Hull Points: ";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << endl;
}

int main()
{
    vector<int> inputSizes = {1000, 5000, 10000, 12000, 15000};
    for (int num : inputSizes)
    {
        string file = "../inputs/" + to_string(num) + ".txt";
        ifstream inputFile(file);
        vector<Point> points;
        Point pt;
        while (inputFile >> pt.x >> pt.y)
            points.push_back(pt);
        inputFile.close();
        auto start = chrono::high_resolution_clock::now();
        convexHullQuick(points);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << "Convex Hull for " << num << " points (Quick Hull Method)" << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        cout << "------------------------------------------" << endl;
    }
}

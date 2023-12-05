#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHullBruteForce(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return;

    vector<Point> hull;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            bool isOnHull = true;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (orientation(points[i], points[j], points[k]) != 2)
                {
                    isOnHull = false;
                    break;
                }
            }
            if (isOnHull)
            {
                hull.push_back(points[i]);
                hull.push_back(points[j]);
            }
        }
    }
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
        convexHullBruteForce(points);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << "Convex Hull for " << num << " points (Brute-Force Method)" << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        cout << "------------------------------------------" << endl;
    }
}

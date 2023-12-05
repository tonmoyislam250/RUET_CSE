#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

struct Point
{
    int x, y;
};
Point lowestPoint;
int squaredDistance(Point p1, Point p2)
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool comparePolarAngles(Point p1, Point p2)
{
    int orient = orientation(lowestPoint, p1, p2);
    if (orient == 0)
        return squaredDistance(lowestPoint, p2) >= squaredDistance(lowestPoint, p1);
    return orient == 2;
}
void convexHullGrahamScan(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
    {
        cout << "Convex Hull not possible with less than 3 points." << endl;
        return;
    }
    lowestPoint = points[0];
    int lowestIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < lowestPoint.y || (points[i].y == lowestPoint.y && points[i].x < lowestPoint.x))
        {
            lowestPoint = points[i];
            lowestIndex = i;
        }
    }
    swap(points[0], points[lowestIndex]);
    sort(points.begin() + 1, points.end(), comparePolarAngles);
    stack<Point> convexHullStack;
    convexHullStack.push(points[0]);
    convexHullStack.push(points[1]);
    for (int i = 2; i < n; i++)
    {
        while (convexHullStack.size() > 1)
        {
            Point p2 = convexHullStack.top();
            convexHullStack.pop();
            Point p1 = convexHullStack.top();
            if (orientation(p1, p2, points[i]) == 2)
            {
                convexHullStack.push(p2);
                break;
            }
        }
        convexHullStack.push(points[i]);
    }
    cout << "Convex Hull Points: ";
    while (!convexHullStack.empty())
    {
        Point p = convexHullStack.top();
        cout << "(" << p.x << ", " << p.y << ") ";
        convexHullStack.pop();
    }
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
        convexHullGrahamScan(points);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << "Convex Hull for " << num << " points (Graham Scan)" << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        cout << "------------------------------------------" << endl;
    }
    return 0;
}

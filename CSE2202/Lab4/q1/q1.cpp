#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

void Knapsack(double varArr[], double Profit[], double weight[], int n, int M, double X[], bool flag = false)
{
    pair<double, int> items[n];
    for (int i = 0; i < n; i++)
        items[i] = make_pair(varArr[i], i);
    for (int i = 0; i < n; i++)
        cout << items[i].first << " " << weight[i] << " " << Profit[i] << endl;
    if (flag == false)
        sort(items, items + n); 
    else if (flag == true)
        sort(items, items + n, greater<pair<double, int>>());

    int c = 0;
    double sum = 0.0;
    cout << "Ratio"
         << " weight"
         << " Profit\n";

    while (M > 0 && c < n)
    {
        int i = items[c].second;
        double taken = (M < weight[i]) ? M : weight[i];
        X[i] = taken / weight[i];
        sum += X[i] * Profit[i];
        M -= taken;
        c++;
    }
    cout << "Selected fractions of items: ";
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << " ";
        X[i] = 0.0;
    }
    cout << endl;
    cout << "Total profit: " << sum << endl;
}

int main()
{
    ifstream inputFile("knapsack.txt");
    int n, M, j = 1;

    while (inputFile >> n >> M)
    {
        cout << "test case " << j++ << endl;
        double P[n], W[n], X[n];
        for (int i = 0; i < n; i++)
            inputFile >> P[i];
        for (int i = 0; i < n; i++)
            inputFile >> W[i];
        double PbyW[n];
        for (int i = 0; i < n; i++)
            PbyW[i] = (double)P[i] / W[i];
        memset(X, 0.0, sizeof(X));
        cout << "Case 1: Max Profit/Weight Ratio (Optimum Solution) \n";
        Knapsack(PbyW, P, W, n, M, X, true);
        // cout << "Case 2: Max Profit \n";
        // Knapsack(P, P, W, n, M, X, true);
        // cout << "Case 3: Less Weight \n";+
        // Knapsack(W, P, W, n, M, X, false);
        // cout << "Case 4: Max Weight\n";
        // Knapsack(W, P, W, n, M, X, true);
    }
    return 0;
}

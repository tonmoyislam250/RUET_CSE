#include <bits/stdc++.h>
using namespace std;
// dijkstra algorithm for finding shortest path input is adjacency matrix
int main()
{
    int n;
    cin >> n;
    int a[n][n];
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    }

    int s;
    cin >> s;

    int dist[n];
    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
    
    dist[s] = 0;
    int vis[n];

    for (i = 0; i < n; i++)
        vis[i] = 0;
    
    for (i = 0; i < n; i++)
    {
        int min = INT_MAX;
        int u;
        for (j = 0; j < n; j++)
        {
            if (vis[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (vis[j] == 0 && a[u][j] != 0 && dist[u] != INT_MAX && dist[u] + a[u][j] < dist[j])
                dist[j] = dist[u] + a[u][j];
        }
    }
    
    for (i = 0; i < n; i++)
        cout << dist[i] << " ";
    return 0;
}

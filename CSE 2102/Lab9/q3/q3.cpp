#include <iostream>
#define MAX 1000

using namespace std;

bool isBipartite(int graph[MAX][MAX], int n)
{
    int colors[MAX];
    for (int i = 0; i < n; ++i)
        colors[i] = -1;
    colors[0] = 0;
    for (int vertex = 0; vertex < n; ++vertex)
    {
        for (int i = 0; i < n; ++i)
        {
            if (graph[vertex][i] == 1)
            {
                if (colors[i] == -1)
                    colors[i] = 1 - colors[vertex];
                else if (colors[i] == colors[vertex])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of vertices. Please enter a value between 1 and " << MAX << "." << endl;
        return 1;
    }

    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0 && graph[i][j] != 1)
            {
                cout << "Invalid adjacency matrix. Please enter only 0s and 1s." << endl;
                return 1;
            }
        }
    }

    if (isBipartite(graph, n))
        cout << "The graph is bipartite." << endl;
    else
        cout << "The graph is not bipartite." << endl;

    return 0;
}

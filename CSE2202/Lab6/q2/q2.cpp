#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int INF = 1e9;

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int weight)
{
    graph[u].emplace_back(v, weight);
    graph[v].emplace_back(u, weight); // Adding for undirected graph
}

vector<int> primMST(vector<vector<pair<int, int>>> &graph, int start)
{
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    return parent;
}

int main()
{
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    vector<int> parent = primMST(graph, 0);

    cout << "Edges in MST:" << endl;
    for (int i = 1; i < V; ++i)
    {
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }

    return 0;
}

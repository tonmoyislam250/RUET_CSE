#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e)
    {
        V = v;
        E = e;
        edges.resize(E);
    }

    void addEdge(int src, int dest, int weight, int index)
    {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }

    int find(vector<int> &parent, int i)
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }


    void KruskalMST()
    {
        vector<Edge> result(V - 1);
        int i = 0; 

        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
             { return a.weight < b.weight; });

        vector<int> parent(V, -1);
        vector<int> rank(V, 0);

        while (i < V - 1 && edges[i].src != -1)
        {
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y)
            {
                result[i - 1] = next_edge;
                Union(parent, rank, x, y);
            }
        }

        cout << "Edges in MST:" << endl;
        for (i = 0; i < V - 1; ++i)
            cout << result[i].src << " - " << result[i].dest << " Weight: " << result[i].weight << endl;
    }
};

int main()
{
    int V = 5;
    int E = 7;

    Graph graph(V, E);

    graph.addEdge(0, 1, 2, 0);
    graph.addEdge(0, 3, 6, 1);
    graph.addEdge(1, 2, 3, 2);
    graph.addEdge(1, 3, 8, 3);
    graph.addEdge(1, 4, 5, 4);
    graph.addEdge(2, 4, 7, 5);
    graph.addEdge(3, 4, 9, 6);

    graph.KruskalMST();
    return 0;
}

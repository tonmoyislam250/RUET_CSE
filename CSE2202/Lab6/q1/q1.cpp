#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int weight;
    vector<pair<int, int>> children; // child node, edge weight
};

void addEdge(unordered_map<int, Node> &tree, int u, int v, int w)
{
    tree[u].children.emplace_back(v, w);
    tree[v].children.emplace_back(u, w); // Adding for undirected tree
}

void TVS(unordered_map<int, Node> &tree, int node, unordered_map<int, int> &d, int parentWeight, int limit, vector<int> &result)
{
    if (node == 0)
    {
        d[node] = 0;
    }
    for (auto &child : tree[node].children)
    {
        int v = child.first;
        int w = child.second;
        if (v != parentWeight)
        {
            TVS(tree, v, d, node, limit, result);
            d[node] = max(d[node], d[v] + w);
        }
    }
    if (node != 0 && (d[node] > limit))
    {
        result.push_back(node);
        d[node] = 0;
    }
}

vector<int> splitVertices(unordered_map<int, Node> &tree, int limit)
{
    vector<int> result;
    unordered_map<int, int> d;
    TVS(tree, 0, d, -1, limit, result);
    return result;
}

int main()
{
    unordered_map<int, Node> tree;
    addEdge(tree, 0, 1, 4);
    addEdge(tree, 0, 2, 2);
    addEdge(tree, 1, 3, 2);
    addEdge(tree, 2, 4, 1);
    addEdge(tree, 2, 5, 3);
    addEdge(tree, 3, 6, 1);
    addEdge(tree, 3, 7, 4);
    addEdge(tree, 5, 8, 2);
    addEdge(tree, 5, 9, 3);

    vector<int> result = splitVertices(tree, 5);

    cout << "Vertices to split: ";
    for (int v : result)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

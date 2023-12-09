#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
int subtreeSize[MAXN];

void calculateSubtreeSizes(int node, int parent)
{
    subtreeSize[node] = 1;
    for (int child : tree[node])
    {
        if (child != parent)
        {
            calculateSubtreeSizes(child, node);
            subtreeSize[node] += subtreeSize[child];
        }
    }
}

int findCentroid(int node, int parent, int treeSize)
{
    for (int child : tree[node])
    {
        if (child != parent && subtreeSize[child] > treeSize / 2)
        {
            return findCentroid(child, node, treeSize);
        }
    }
    return node;
}

void decomposeTree(int node, int parent)
{
    calculateSubtreeSizes(node, -1);
    int centroid = findCentroid(node, -1, subtreeSize[node]);

    for (int child : tree[centroid])
    {
        tree[child].erase(find(tree[child].begin(), tree[child].end(), centroid));
        decomposeTree(child, centroid);
    }
    tree[centroid].clear();
}

int main()
{
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    cout << "Enter the tree edges (node1 node2):" << endl;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    decomposeTree(1, -1);

    return 0;
}

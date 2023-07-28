#include<iostream>
#include<vector>
using namespace std;

class Graph
{
public:
    vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n);

        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (u v): ";
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Graph g;
    vector<vector<int>> adjacency = g.printAdjacency(n, m, edges);

    cout << "Adjacency list:\n";
    for(int i = 0; i < n; i++)
    {
        cout << i << ":";
        for(int j = 0; j < adjacency[i].size(); j++)
        {
            cout << " " << adjacency[i][j];
        }
        cout << endl;
    }

    return 0;
}

#include<iostream>
#include<unordered_map>
#include<list>
#include<limits>
#include<stack>
#include<vector>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) 
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj() 
    {
        for (auto i : adj) 
        {
            cout << i.first << " -> ";
            for (auto j : i.second) 
            {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl;
        }
    }

    void topologicalSort(int node, unordered_map<int, bool>& visited, stack<int>& topo) 
    {
        visited[node] = true;

        for (auto neighbor : adj[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                topologicalSort(neighbor.first, visited, topo);
            }
        }

        topo.push(node);
    }

    vector<int> shortestPath(int src) 
    {
        int n = adj.size();
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;

        stack<int> topo;
        unordered_map<int, bool> visited;

        for (auto i : adj) 
        {
            if (!visited[i.first]) 
            {
                topologicalSort(i.first, visited, topo);
            }
        }

        while (!topo.empty()) 
        {
            int node = topo.top();
            topo.pop();

            if (dist[node] != numeric_limits<int>::max()) 
            {
                for (auto neighbor : adj[node]) 
                {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    if (dist[node] + weight < dist[v]) 
                    {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
        }

        return dist;
    }
};

int main() 
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int src = 1;
    vector<int> dist = g.shortestPath(src);

    cout << "Shortest paths from node " << src << ":\n";

    for (int i = 0; i < dist.size(); ++i) 
    {
        if (dist[i] == numeric_limits<int>::max()) 
        {
            cout << "Node " << i << " is unreachable.\n";
        }
         else 
         {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}

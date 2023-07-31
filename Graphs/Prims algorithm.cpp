#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <limits>
#include <set>
using namespace std;

// Function to add an edge to the graph
void addEdge(unordered_map<int, list<pair<int, int>>>& graph, int source, int destination, int weight)
{
    graph[source].push_back(make_pair(destination, weight));
    graph[destination].push_back(make_pair(source, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(unordered_map<int, list<pair<int, int>>>& graph)
{
    int v = graph.size();

    // Set to store vertices and their respective key values
    set<pair<int, int>> pq;

    int src = 0; // Start vertex

    // Create a vector for key values and initialize all of them as infinite
    vector<int> key(v, numeric_limits<int>::max());

    // Create a vector to store the parent of each vertex
    vector<int> parent(v, -1);

    // Insert the start vertex in the set and initialize its key value as 0
    pq.insert(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        // Traverse all adjacent vertices of the current vertex
        for (auto it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            int v = (*it).first;
            int weight = (*it).second;

            // If v is not yet included in MST and weight of (u,v) is smaller than current key of v,
            // then update the key value and parent of v and insert it into the set
            if (pq.find(make_pair(key[v], v)) != pq.end() && weight < key[v])
            {
                pq.erase(pq.find(make_pair(key[v], v)));
                key[v] = weight;
                pq.insert(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < v; ++i)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    unordered_map<int, list<pair<int, int>>> graph;

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 4, 5);

    // Find the minimum spanning tree
    primMST(graph);

    return 0;
}

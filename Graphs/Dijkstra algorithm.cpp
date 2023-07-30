#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<limits>
#include<set>   

using namespace std;

void dijkstra(unordered_map<int, list<pair<int, int>>>& graph, int start, vector<int>& distances)
{
    int numVertices = graph.size();
    distances.resize(numVertices, numeric_limits<int>::max());

    //set to store vertices based on min distance
    set<pair<int, int>> pq;

    //Distance to start vertex is 0
    distances[start] = 0;
    pq.insert({0, start});

    while(!pq.empty())
    {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        //visit each adjacent node of u
        for (auto& neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            //update distance if a shorter path is found
            if(distances[u] + weight < distances[v])
            {
                pq.erase({distances[v], v});  // Remove old distance for vertex v
                distances[v] = distances[u] + weight;
                pq.insert({distances[v], v});  // Insert updated distance for vertex v
            }
        }
    }
}

int main()
{
    int numVertices, numEdges;

    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    unordered_map<int, list<pair<int, int>>> graph;

    cout << "Enter the edges (source, destination, weight): " << endl;

    for (int i = 0; i < numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    vector<int> distances;
    dijkstra(graph, startVertex, distances);

    cout << "Shortest distance from vertex " << startVertex << ":" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertex " << i << ": ";
        if (distances[i] == numeric_limits<int>::max())
        {
            cout << "not reachable" << endl;
        }
        else
        {
            cout << distances[i] << endl;
        }
    }

    return 0;
}

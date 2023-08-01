#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include<algorithm>

using namespace std;

void BFS(unordered_map<int, list<int>>& graph, int startVertex)
{
    unordered_map<int, bool> visited;
    queue<int> bfsQueue;

    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty())
    {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        cout << currentVertex << " ";

        for (int adjacentVertex : graph[currentVertex])
        {
            if (!visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                bfsQueue.push(adjacentVertex);
            }
        }
    }
}

/*
The BFS function performs a breadth-first search traversal of the graph starting from the startVertex.
It initializes an unordered_map called visited to keep track of visited vertices and a queue called bfsQueue to store the vertices to be visited.
The startVertex is marked as visited and added to the queue.
The while loop continues until the bfsQueue is empty.
It dequeues a vertex from the front of the queue and prints it.
For each adjacent vertex of the current vertex, if it has not been visited before, it marks it as visited and enqueues it.


*/

vector<int> shortestPathBFS(unordered_map<int, list<int>>& graph, int start, int end)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    unordered_map<int, int> distance;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == end)
            break;

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    if (!visited[end])
    {
        return {};
    }

    vector<int> path;
    int current = end;
    while (current != start)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    return path;
}

/*
The shortestPathBFS function finds the shortest path using breadth-first search between start and end vertices.
It initializes unordered_map variables: visited to track visited vertices, parent to store the parent of each vertex in the path,
and distance to store the distance from the start vertex to each vertex.
A queue called q is created to perform the BFS traversal.
The start vertex is marked as visited and added to the queue.
The while loop continues until the queue q is empty.
It dequeues a vertex current from the front of the queue.
If the current vertex is equal to the end vertex, it means we have found the shortest path, so the loop is terminated.
For each neighbor of the current vertex in the graph, if it has not been visited before, it marks it as visited, 
sets its parent as current, updates the distance, and enqueues it.
If the end vertex was not visited, it means there is no path from start to end, so an empty vector is returned.
Otherwise, a vector called path is initialized to store the shortest path.
Starting from the end vertex, the function traverses back to the start vertex using the parent mapping and adds each vertex to the path.
Finally, the path vector is reversed to obtain the correct order of vertices from start to end and is returned.
*/

int main()
{
    int numVertex, numEdge;
    
    cout << "Enter the number of vertices: ";
    cin >> numVertex;

    cout << "Enter the number of edges: ";
    cin >> numEdge;

    unordered_map<int, list<int>> graph;

    cout << "Enter the edges (u, v) in the graph" << endl;
    for (int i = 0; i < numEdge; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the start vertex for BFS traversal: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(graph, startVertex);
    cout << endl;

    int endVertex;
    cout << "Enter the end vertex to find the shortest path: ";
    cin >> endVertex;

    vector<int> shortestPath = shortestPathBFS(graph, startVertex, endVertex);

    cout << "Shortest path from " << startVertex << " to " << endVertex << ": ";
    for (int vertex : shortestPath)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

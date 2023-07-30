#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

void DFS(unordered_map<int, list<int>>& graph, int startVertex)
{
    unordered_map<int, bool> visited;  //keep track of visited vertices
    stack<int> dfsStack;  //stack for DFS traversal

    //mark the start vertex as visited and push it onto the stack
    visited[startVertex] = true;
    dfsStack.push(startVertex);

    while(!dfsStack.empty())
    {
        int currentVertex = dfsStack.top();
        dfsStack.pop();

        cout << currentVertex << " ";

        //visit all the adjacent vertices of the current vertex
        for(auto it = graph[currentVertex].begin(); it != graph[currentVertex].end(); it++)
        {
            int adjacentVertex = *it;    //retrive the value of current neighbour

            //if the adjacent vertex is not visited, mark it as visited and push it onto the stack
            if(!visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                dfsStack.push(adjacentVertex); 
            }
        }
    }
}

int main()
{
    int numVertex, numEdge;
    
    cout << "Enter the number of vertices: ";
    cin >> numVertex;

    cout << "Enter the number of edges: ";
    cin >> numEdge;

    unordered_map<int, list<int>> graph; //adjacency list representation of the graph

    cout << "Enter the edges (u, v) in the graph:" << endl;
    for(int i = 0; i < numEdge; i++)
    {
        int u, v;
        cin >> u >> v;

        //adding edges to the adjacency list
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the start vertex for DFS traversal: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFS(graph, startVertex);

    return 0;
}

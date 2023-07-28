#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void BFS(unordered_map<int, list<int>>& graph, int startVertex)
{
    unordered_map<int, bool> visited;  //keep track of visited vertex
    queue<int> bfsQueue;  //queue for bfs traversal

    //mark the start vertex as visited and put that vertex in the queue
    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    while(!bfsQueue.empty())
    {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        cout<< currentVertex << " ";

        //visit all the adjacent vertex of the current vertex
        for(auto it = graph[currentVertex].begin(); it != graph[currentVertex].end(); it++)
        {
            int adjacentVertex = *it;

            //if the adjacent vertex is not visited , mark it as visited and enqueue it
            if(!visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                bfsQueue.push(adjacentVertex);
            }
        }
    }

}

int main()
{
    int numVertex, numEdge;
    
    cout << "Enter the number of vertices:" ;
    cin >> numVertex;

    cout << "Enter the number of edges:" ;
    cin >> numEdge;

    unordered_map<int, list<int> > graph; //adjacency list representation of the graph

    cout<< "Enter the edges (u, v) in the graph" << endl;
    for(int i=0; i<numEdge; i++)
    {
        int u, v;
        cin >> u >> v;

        //adding edges to the adjacency list
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startVertex;
    cout<< "Enter the start vertex for bfs traversal:" ;
    cin>> startVertex;

    cout<< "BFS traversal starting from vertex "<< startVertex << " : ";
    BFS(graph, startVertex);


}

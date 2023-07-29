#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

bool hasCycleDFS(unordered_map<int, list<int> >&graph, int currentVertex, unordered_map<int, bool> &visited, int parent)
{
    visited[currentVertex] = true;

    for(int adjacentVertex : graph[currentVertex])
    {
        if(visited.find(adjacentVertex) == visited.end())
        {
            if(hasCycleDFS(graph, adjacentVertex, visited, currentVertex))
            {
                return true;
            }
        }
        else if(adjacentVertex != parent)
        {
            //if the adjacent vertex is visiteed and not the parent of the currecnt vertex
            return true;
        }
    }

    return false;
}

bool hasCycleInGraph(unordered_map<int, list<int> > &graph)
{
    unordered_map<int, bool> visited;

    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        int startVertex = it->first;
        if(visited.find(startVertex) == visited.end())
        {
            if(hasCycleDFS(graph, startVertex, visited, -1))
            {
                return true;
            } 
        }
    }
    return false;
}

int main()
{
    int n,m;

    cout<<"Enter the number of nodes in the graph:";
    cin>>n;

    cout<<"Enter the number of edges in the graph:";
    cin>>m;

    unordered_map<int, list<int> > graph;

    cout<<"Enter the edges (u,v) in the graph:"<<endl;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(hasCycleInGraph(graph))
    {
        cout<<"cycle detected in the graph"<<endl;
    }
    else
    {
        cout<<"cycle not detected in the graph"<<endl;
    }
    
}

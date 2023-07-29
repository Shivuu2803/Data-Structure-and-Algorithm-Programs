#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;

bool hasCycleDfS(unordered_map<int, list<int>> &graph, int startVertex, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[startVertex] = true;
    dfsVisited[startVertex] = true;

    for(int adjacentVertex : graph[startVertex])
    {
        if(!visited[adjacentVertex])
        {
            if(hasCycleDfS(graph, adjacentVertex, visited, dfsVisited))
            {
                return true;
            }
        }
        else if(dfsVisited[adjacentVertex])
        {
            //if the adjacent vertex is visited and present in the current dfs traversal
            return true;
        }
    }

    dfsVisited[startVertex] = false;
    return false;
}

bool hasCycleInGraph(unordered_map<int, list<int>> &graph)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(auto it= graph.begin(); it!= graph.end(); it++)
    {
        int startVertex = it->first;
        if(!visited[startVertex])
        {
            if(hasCycleDfS(graph, startVertex, visited, dfsVisited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;

    cout<< "enter the number of nodes in the graph:" ;
    cin>> n;

    cout<< "enter the number of edges in the graph:";
    cin>> m;

    unordered_map<int, list<int> > graph;

    cout<< "enter the edges (u, v) in the graph:" << endl;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
    }

    if(hasCycleInGraph(graph))
    {
        cout<< "cycle detected in the graph."<< endl;
    }
    else
    {
        cout<< "cycle not detected in the graph."<< endl;
    }

    return 0;

}

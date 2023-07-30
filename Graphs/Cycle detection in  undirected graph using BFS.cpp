//using BFS
//jb kisi node ka visited true aa jaye aur wo kisi aur node ke parent na ho tb cycle prenet hia

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

bool hasCycleBFS(unordered_map<int, list<int> > &graph, int startVertex)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> bfsQueue;

    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    while(!bfsQueue.empty())
    {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        for(auto it = graph[currentVertex].begin(); it != graph[currentVertex].end(); it++)
        {
            int adjacentVertex = *it;

            if(!visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                bfsQueue.push(adjacentVertex);
                parent[adjacentVertex] =currentVertex;
            }
            else if(parent[currentVertex] != adjacentVertex)
            {
                //if the adjacent vertex is visited and not the parent of current vertex
                return true;
            }
        }
    }

    return false;
}

bool hasCycleInGraph(unordered_map<int, list<int> >& graph)
{
    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        int startVertex = it->first;
        if(!hasCycleBFS(graph, startVertex))
        {
            return true;
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
        graph[v].push_back(u);
    }

    if(hasCycleInGraph(graph))
    {
        cout<< "cycle detected in the graph"<< endl;
    }
    else
    {
        cout<< "cycle not detected in the graph"<< endl;
    }

    return 0;

}

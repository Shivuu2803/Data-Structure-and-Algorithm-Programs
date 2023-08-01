#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void DFS(int node, unordered_map<int, list<int>>& graph, unordered_map<int, bool>& visited, stack<int>& st) 
{
    visited[node] = true;
    for (auto neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            DFS(neighbor, graph, visited, st);
        }
    }
    st.push(node);
}

void topologicalSort(unordered_map<int, list<int>>& graph) 
{
    unordered_map<int, bool> visited;
    stack<int> st;

    for (auto node : graph) 
    {
        visited[node.first] = false;
    }

    for (auto node : graph) 
    {
        if (!visited[node.first]) 
        {
            DFS(node.first, graph, visited, st);   //jo node visited nhi hai uske liye dfs call kr dia
        }
    }

    while (!st.empty()) 
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() 
{
    unordered_map<int, list<int>> graph;

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);

    cout << "Topological sort: ";
    topologicalSort(graph);

    return 0;
}

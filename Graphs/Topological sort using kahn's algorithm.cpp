//step 1 : find indegree of all steps
//step 2 : make a queue and insert all nodes having 0 indegree
//step 3 : do bfs means queue ka front element nikalo , usko naswr me store kro, the usko queue se pop kr do, then uske ajacent nodes ko queue me daal do
//(but ajacent me jis ke degree 0 hoti jyge usko hi daalna hai bs) jb hum front element pop krenge to uske ajacent nodes ki degree km hogi hi
//step 4 : jo hum pop krke store kr rhe hai wahi answr hai humara 

#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include<queue>

using namespace std;

vector<int> topologicalSort(unordered_map<int, list<int>> &graph, int n)
{
    unordered_map<int, int> inDegree;
    vector<int> result;
    queue<int> q;

    //calculate in degree for each node
    for(const auto &pair : graph)  //const se extra coppies nhi bnte pair ke 
    {
        int node = pair.first;
        inDegree[node] = 0;
    }

    for(auto & pair : graph)
    {
        int node = pair.first;
        for(int neighbour : graph[node])
        {
            inDegree[neighbour]++;
        }
    }

    //enqueue node with in degree 0
    for(auto &pair : inDegree)
    {
        int node = pair.first;
        if(inDegree[node] == 0)
        {
            q.push(node);
        }
    }

    //process the queue
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        //decrement in degree of adjacent node
        for (int neighbor : graph[node]) 
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) 
            {
                q.push(neighbor);
            }
        }
    }

    // Check for a cycle
    if (result.size() != n) 
    {
        result.clear();  // Clear the result vector to indicate failure
    }

    return result;

}



int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    unordered_map<int, list<int>> graph;

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sortedOrder = topologicalSort(graph, n);

    if(sortedOrder.empty())
    {
        cout<<"the graph has a cycle . topological cycle is not possible"<<endl;
    }
    else
    {
        cout<<"topological order: ";
        for(int node : sortedOrder)
        {
            cout<< node << " ";
        }

        cout<< endl;
    }

    return 0;

}

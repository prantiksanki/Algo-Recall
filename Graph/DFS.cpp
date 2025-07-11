#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

class DFS
{
    public:
    void dfs(int start, vector<int>& visited, vector<int>& result, map<int, vector<int>>& adj)
    {
        visited[start] = 1; // Mark the current node as visited
        result.push_back(start); // Add it to the result

        for (int i = 0; i < adj[start].size(); i++)
        {
            int neighbour = adj[start][i];
            if (!visited[neighbour]) // If the neighbour hasn't been visited
            {
                dfs(neighbour, visited, result, adj); // Recur for the neighbour
            }
        }
    }
    public :
        void dfsTraversal(int start , map<int, vector<int>>&adj)
        {
            int V = adj.size() ;
            vector<int>visited(V, 0) ; 
            vector<int>result ; 

            dfs(start, visited, result, adj) ;

            cout << "DFS Traversal: ";
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
            return ;

        }
} ; 


int main()
{
    DFS dfs;
    map<int, vector<int>> adj;

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0,1,3,4};
    adj[3] = {2};
    adj[4] = {2};

    dfs.dfsTraversal(0, adj);

    return 0;
}
#include<iostream> 
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;


class Toposort
{

    public:

    void dfs(int start, vector<int>& visited, stack<int>& st, map<int, vector<int>>& adj)
    {
        visited[start] = 1; 

        for (int i = 0; i < adj[start].size(); i++)
        {
            int neighbour = adj[start][i];
            if (!visited[neighbour]) 
            {
                dfs(neighbour, visited, st, adj); 
            }
        }
        st.push(start); 
    }
    
    void usingDfs(map<int, vector<int>>mp, int v, vector<int>&ans)
    {
        stack<int>st; 
        vector<int>visited(v, 0); 
        for(int i = 0 ; i < v ; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, st, mp); 

            }
        }


        while(!st.empty())
        {
            ans.push_back(st.top()); 
            st.pop();
        }
    }



} ; 


int main()
{
    Toposort toposort;
    map<int, vector<int>> adj;
    vector<int> ans;

    // Example graph
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0,1} ; 
    adj[5] = {0,2} ; 

    toposort.usingDfs(adj, 4, ans);

    // Print the topological order
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

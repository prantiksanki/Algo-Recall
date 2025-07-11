#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class BFS
{
public:
    void bfs(int start, map<int, vector<int>>& adj)
    {
        map<int, bool> visited;   // safer for arbitrary labels
        vector<int> res;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            res.push_back(frontNode);

            for (int i = 0; i < adj[frontNode].size(); i++)
            {
                int neighbour = adj[frontNode][i];
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
};

int main()
{
    BFS obj;
    map<int, vector<int>> adj;
    adj[1] = {2,6};
    adj[2] = {1,3,4};
    adj[3] = {2};
    adj[4] = {2,5};
    adj[5] = {4,8};
    adj[6] = {1,7,9};
    adj[7] = {6,8};
    adj[8] = {5,7};
    adj[9] = {6};

    obj.bfs(1, adj);
    return 0;
}

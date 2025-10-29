#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class DSU
{
  private:
    vector<int> parent, rank;
    public:

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};



int kruskalMST(vector<vector<int>>&edges, int n)
{

    DSU dsu(n);

    sort(edges.begin(), edges.end()) ; 

    int mstWeight = 0 ;
    for(auto it : edges)
    {
        int wt = it[0] ;
        int u = it[1] ;
        int v = it[2] ;

        if(dsu.find(u) != dsu.find(v))
        {
            dsu.unionByRank(u, v) ;
            mstWeight += wt ;
        }
    } 

    return mstWeight ;
}


int main()
{
    int V = 4;
    vector<vector<int>> edges = {
         {10, 0, 1}, {15, 1, 3}, {4, 2, 3}, {6, 2, 0}, {5, 0, 3}
    };

    int mstWeight = kruskalMST(edges, V);
    cout << "Weight of MST is " << mstWeight << endl;
    return 0;

}
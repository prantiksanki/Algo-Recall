#include<iostream>
#include<vector>
#include<map>
// #include<graph>
using namespace std ; 



class adjacency_list
{
    public: 
    map<int, vector<int>>mp  ;
    bool directed ; 

    adjacency_list(bool directed = false)
    {
        this->directed = directed ; 
    }
    
    public:
        void buildAdjacent(int u, int v, bool direction)
        {
            // DIRECTION = 0 --------> Undirected
            // DIRECTION = 1 --------> Directed

            mp[u].push_back(v) ; 
            if(direction == 0)
            {
                mp[v].push_back(u) ; 
            }

            return ; 
        }

        void printAdjacencyList()
        {
            for(auto it : mp)
            {
                cout << it.first << " : " ; 
                for(auto element : it.second)
                {
                    cout << element << " " ; 
                }
                cout << endl ; 
            }
        }
} ; 


int main ()
{
    bool isDirected ; 
    cout << "Graph directed or not ? 0/1  :" << endl ; 
    cin >> isDirected ;
    adjacency_list g(isDirected); 
    int n, m ; 
    cout << "Enter no of nodes" << endl ; 
    cin >> n ; 

    cout << "Enter no of edges" << endl ; 
    cin >> m ; 


    for(int i = 0 ; i < m ; i++)
    {
        int u,v  ;
        cin >> u >> v ; 
        g.buildAdjacent(u,v,0) ; 
    }
    cout << endl ; 

    cout << "Your adjacency list is : " << endl ;

    g.printAdjacencyList() ; 

    return 0 ; 
}
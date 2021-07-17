class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool DFS(int u,int p,vector<int> g[],vector<bool> &vis)
    {
        vis[u]=true;
        for(auto i:g[u])
        {
            if(!vis[i])
            {
                if(DFS(i,u,g,vis))
                return true;
            }
            else if(i!=p )
            return true;
            
        }
        return false;
    }
    
    
    
	bool isCycle(int V, vector<int>g[])
	{
	    // Code here
	    vector<bool> vis(V);
	    for(int i=0;i<V;i++)
	    if(!vis[i] && DFS(i,-1,g,vis))
	    return true;
	    return false;
	}
};

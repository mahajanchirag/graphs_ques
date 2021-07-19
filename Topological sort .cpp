class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,vector<int> adj[],stack<int> &stk,vector<int> &visited)
	{
	    visited[node]=1;
	    for(auto i:adj[node])
	    {
	        if(visited[i]==0)
	        {
	            dfs(i,adj,stk,visited);
	        }
	    }
	    
	    stk.push(node);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> stk;
	    vector<int> visited(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            dfs(i,adj,stk,visited);
	        }
	    }
	    
	    vector<int> ans;
	    while(!stk.empty())
	    {
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans;
	}
};

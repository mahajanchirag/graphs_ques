class Solution {
public:
    
    void dfs(int i,int n,vector<bool> &visited,vector<vector<int>>& isConnected)
    {
        visited[i]=true;
        
        for(int j=0;j<n;j++)
        {
            if(isConnected[i][j]==1 && visited[j]==false && i!=j)
            {
                dfs(j,n,visited,isConnected);
            }
        }
        
        return;
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n=isConnected.size();
        vector<bool> visited(n,false);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,n,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};

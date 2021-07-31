class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //outdegree-indegree shoul be equal to n-1
        
        vector<int> degrees(n+1,0);
        
        for(auto i:trust)
        {
            degrees[i[1]]++;
            degrees[i[0]]--;
        }
        
        for(int i=1;i<n+1;i++)
        {
            if(degrees[i]==n-1)
            {
                return i;
            }
        }
        
        return -1;
        
        
        
        
    }
};

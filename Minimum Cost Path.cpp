class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isValid(int i , int j , int n){
		if(i>= 0 && i<= n && j>=0 && j<=n) return true;
		return false;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        vector<vector<int>> weight(grid.size() , vector<int>(grid[0].size() , INT_MAX));
    	int n = grid.size() - 1;
    	priority_queue<
    		pair<int , pair<int ,int>> ,
			vector<pair<int , pair<int , int>>> ,
			greater<pair<int , pair<int , int>>> 
		> pq;
    	pq.push({ grid[n][n] , {n , n}});
    	int moveX[] = {1 , -1 , 0 , 0};
    	int moveY[] = {0 , 0 , 1 , -1};
    	while(!pq.empty()){
    		int w = pq.top().first;
    		int i = pq.top().second.first;
    		int j = pq.top().second.second;
    		pq.pop();
    		for(int c = 0 ; c < 4 ; c++){
    			int i_ = i+moveX[c];
    			int j_ = j+moveY[c];
    			if(isValid(i_ , j_ , n)){
    				if(w+grid[i_][j_] < weight[i_][j_]){
    					weight[i_][j_] = w+grid[i_][j_];
    					pq.push({weight[i_][j_] , {i_ , j_}});
    				}
    			}
    			if(i_==0 && j_==0) return weight[i_][j_];
    		}
    	}
    	return 0;
    }
};

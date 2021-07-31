class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int starting_pixel)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=starting_pixel)
        {
            return;
        }
        
        image[sr][sc]=newColor;
        dfs(image,sr+1,sc,newColor,starting_pixel);
        dfs(image,sr-1,sc,newColor,starting_pixel);
        dfs(image,sr,sc+1,newColor,starting_pixel);
        dfs(image,sr,sc-1,newColor,starting_pixel);
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int starting_pixel=image[sr][sc];
        if(starting_pixel==newColor)
        {
            return image;
        }
        dfs(image,sr,sc,newColor,starting_pixel);
        return image;
    }
};

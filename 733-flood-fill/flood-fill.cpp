class Solution {
    private:
    void dfs(int row, int col, int color, vector<vector<int>>& vis, vector<vector<int>>& image){
        int val = image[row][col];
        int n = image.size();
        int m = image[0].size();
        vis[row][col] = color;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow>=0 && newrow<n && newcol >=0 && newcol <m && vis[newrow][newcol] != color && image[newrow][newcol] ==  val){
                dfs(newrow, newcol, color, vis, image);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis = image;
        dfs(sr, sc, color, vis, image);
        
        
        return vis;
    }
};
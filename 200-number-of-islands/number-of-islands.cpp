class Solution {
    private:
    void dfs(int row, int column, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][column] = 1;
        int delrow[] = {-1,+1,0,0};
        int delcol[] = {0,0,+1,-1};
        for(int i=0; i<4; i++){
            int newrow = row + delrow[i];
            int newcol = column + delcol[i];
            if(newrow >=0 && newrow <n && newcol >=0 && newcol <m && vis[newrow][newcol]==0 && grid[newrow][newcol] == '1' ){
                dfs(newrow,newcol, vis, grid);

            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(vis[i][j]==0 && grid[i][j] == '1'){
                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};
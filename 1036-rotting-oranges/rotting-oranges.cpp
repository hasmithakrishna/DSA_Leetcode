class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int count = -1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int x = q.size();
            count++;
            for(int i=0; i<x; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int newrow = row+ delrow[i];
                    int newcol = col+delcol[i];
                    if(newrow>=0 && newrow<m && newcol >=0 && newcol <n && vis[newrow][newcol]==0 && grid[newrow][newcol] == 1){
                        grid[newrow][newcol] = 2;
                        vis[newrow][newcol] = 1;
                        q.push({newrow, newcol});
                    }
                }

            }

        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return max(count,0);

    }
};
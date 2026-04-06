class Solution {
    int bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int count = -1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0; i< size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int newrow = row+delrow[j];
                    int newcol = col+delcol[j];
                        if(newrow>=0 && newrow<m && newcol>=0 && newcol <n && grid[newrow][newcol] == 1){
                            grid[newrow][newcol] = 2;
                            q.push({newrow, newcol});
                }
                }
            }
        }
        return max(count,0);

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int ans = bfs(q, grid);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};

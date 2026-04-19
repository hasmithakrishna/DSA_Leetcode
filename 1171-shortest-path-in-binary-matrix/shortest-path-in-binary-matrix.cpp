class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int,pair<int,int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        if(m == 1 && n == 1) return 1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        q.push({1, {0,0}});
        int delrow[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int delcol[] = {0, 0, -1, 1, 1, -1, 1, -1};
        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i = 0; i< 8; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow>=0 && newrow<m && newcol >=0 && newcol < n && grid[newrow][newcol] == 0 &&d+1 < dist[newrow][newcol]){
                        dist[newrow][newcol] = d+1;
                        if(newrow == m-1 && newcol == n-1) return dist[m-1][n-1];
                        q.push({dist[newrow][newcol], {newrow, newcol}});
                }
            }
        }
        return -1;
        
    }
};


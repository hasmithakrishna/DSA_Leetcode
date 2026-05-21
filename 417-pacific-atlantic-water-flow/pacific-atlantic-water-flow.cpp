class Solution {
    private:
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, queue<pair<int,int>>& q, int m, int n){
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()){
            int sq = q.size();
            for(int i=0; i<sq; i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int newrow = row + delrow[k];
                int newcol = col + delcol[k];
                if(newrow>=0 && newcol >=0 && newrow <m && newcol<n && heights[newrow][newcol]>= heights[row][col] && ocean[newrow][newcol]==0 ){
                q.push({newrow,newcol});
                ocean[newrow][newcol] = 1;
                }
            }
            }

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pac(m, vector<int>(n,0));
        vector<vector<int>> atl(m, vector<int>(n,0));
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;
        for(int i=0; i<n; i++){
            pac[0][i] = 1;
            atl[m-1][i] = 1;
            pq.push({0,i});
            aq.push({m-1,i});
        }
        for(int i=0; i<m; i++){
            pac[i][0] = 1;
            atl[i][n-1] = 1;
            pq.push({i,0});
            aq.push({i,n-1});
        }
        bfs(heights, pac, pq, m, n);
        bfs(heights, atl, aq, m, n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(atl[i][j] == 1 && pac[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
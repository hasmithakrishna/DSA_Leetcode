class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == m-1 && col == n-1) return d;
            for(int i=0; i<4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow >=0 && newrow <m && newcol >=0 && newcol <n){
                    int neweffort = max(abs(heights[row][col] - heights[newrow][newcol]), d);
                    if(neweffort < dist[newrow][newcol]){
                        dist[newrow][newcol] = neweffort;
                        pq.push({dist[newrow][newcol], {newrow, newcol}});
                    }
                }
            }
        }
        return 0;
        
    }
};
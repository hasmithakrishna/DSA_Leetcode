class Solution {
    private:
    void dfs(int Node, vector<int>& vis, vector<vector<int>> isConnected){
        vis[Node] = 1;
        for(int i=0; i<isConnected.size(); i++){
            if(!vis[i] && isConnected[Node][i]==1 && i != Node){
                dfs(i, vis, isConnected);
            }

        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};
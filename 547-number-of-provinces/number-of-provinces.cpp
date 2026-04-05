class Solution {
    private:
    void dfs(int Node, vector<int>& vis, vector<vector<int>> isConnected){
        int n=isConnected.size();
        vis[Node] = 1;
        for(int i=0; i<n; i++){
            if(!vis[i] && isConnected[i][Node]==1 && i!=Node){
                dfs(i,vis,isConnected);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                count++;
                dfs(i, vis, isConnected);
            }
        }

        return count;
    }
};
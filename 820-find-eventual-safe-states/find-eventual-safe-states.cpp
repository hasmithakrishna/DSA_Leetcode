class Solution {
    private:
    bool dfs(int Node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& graph, vector<int>& res){
        vis[Node] = 1;
        pathvis[Node] = 1;
        for(auto it: graph[Node]){
            if(!vis[it]){
                vis[it] = 1;
                pathvis[it] = 1;
                if(dfs(it, vis, pathvis, graph,res)==true) return true;
            }
            else if(pathvis[it] == 1) return true;
        }
        pathvis[Node] = 0;
        res.push_back(Node);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i,vis,pathvis,graph, res);
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;
            }
            while(!q.empty()){
            int Node = q.front();
            q.pop();
            for (auto it: graph[Node]){
                if(color[it] == -1){
                color[it] = 1- color[Node];
                q.push(it);
                }
                else if(color[it] == color[Node]){
                    return false;
                }
            }
            }
        }
        return true;
    }
};
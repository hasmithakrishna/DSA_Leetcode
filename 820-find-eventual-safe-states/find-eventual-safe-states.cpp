class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int s = graph.size();
        vector<int> res;
        vector<int> in(s,0);
        queue<int> q;
        vector<vector<int>> Adj(s);
        for(int i=0; i<s; i++){
        for(auto it: graph[i]){
            Adj[it].push_back(i);
            in[i]++;
        }
        }
        for(int i=0; i< s; i++){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int Node = q.front();
            q.pop();
            for(auto it: Adj[Node]){
                in[it]--;
                if(in[it] == 0 ) q.push(it);
            }
            res.push_back(Node);
        }
        sort(res.begin(), res.end());
        return res;


    }
};
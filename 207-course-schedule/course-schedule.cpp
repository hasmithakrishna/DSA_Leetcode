class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        vector<int> res;
        queue<int> q;
        vector<vector<int>> Adj(numCourses);
        for(auto it: prerequisites){
            int u = it[0];
            int v= it[1];
            in[u]++;
            Adj[v].push_back(u);
        }
        for(int i=0; i<numCourses; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int Node = q.front();
            q.pop();
            for(auto it: Adj[Node]){
                in[it]--;
                if( in[it] == 0) q.push(it);
            }
            res.push_back(Node);
        }
        if(res.size() != numCourses) return false;

        return true;


    }
};
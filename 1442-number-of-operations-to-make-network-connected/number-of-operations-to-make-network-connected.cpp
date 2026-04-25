class Solution {
    vector<int> parent;
    vector<int> sz;
    int count = 0;
    int findparent(int x){
        if(x == parent[x]) return x;
        else 
        return parent[x] = findparent(parent[x]);
    }
    void unionof(int u, int v){
        u = findparent(u);
        v = findparent(v);
        if(u == v){
            count++;
            return;
        }
        if(sz[u] >= sz[v]){
            parent[v] = u;
            sz[u] += sz[v];
        } 
        else{
            parent[u] = v;
            sz[v] += sz[u];
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        sz.resize(n,1);
        int seccount = 0;
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            unionof(u,v);

        }
        for(int i=0; i<n; i++){
            if(findparent(i) == i) seccount++;
        }
        if(count >= seccount-1) return seccount-1;
        else return -1;    
        
    }
};


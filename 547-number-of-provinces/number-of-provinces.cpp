class DSU{
public:
    vector<int> size , parent;

    DSU(int n){
        parent.resize(n);
        size.resize(n , 1);
        iota(parent.begin() , parent.end() , 0);
    }


    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u , int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU d(n);
        for(int i = 0; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(isConnected[i][j]){
                    d.unite(i , j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(d.find(i) == i) cnt++;
        }

        return cnt;


    }
};
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u){
        if(parent[u] == u){
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unite(int u , int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv ) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n -1){
            return -1;
        }

        parent.resize(n);
        rank.resize(n , 0);

        for(int i = 0; i < n ; i++){
            parent[i] = i;
        }


        for(auto &it : connections){
            unite(it[0] , it[1]);
        }

        int cnt = 0;

        for(int i = 0; i < n ; i++){
            if(parent[i] == i){
                cnt++;
            }
        }


        return cnt - 1;
    }
};
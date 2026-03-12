class Solution {

public:
    vector<int> parent , rank;

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }


        return parent[node] = findParent(parent[node]);
    }


    void UnionByRank(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
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


        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        for(auto &it : connections){
            UnionByRank(it[0] , it[1]);
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(parent[i] == i)
                components++;
        }

        return components - 1;
    }
};
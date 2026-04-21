class DSU{
public: 
    vector<int> parent , rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n , 0);

        for(int i = 0; i < n ; i++){
            parent[i] = i;

        }
    }

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x , int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);


        for(auto &it : allowedSwaps){
            dsu.unite(it[0] , it[1]);
        }

        unordered_map<int , unordered_map<int , int>> mpp;

         for(int i = 0; i < n ; i++){
            int root = dsu.find(i);
            mpp[root][source[i]]++;
         }


        int ans = 0;

        for(int i = 0; i < n ; i++){
            int root = dsu.find(i);

            if(mpp[root][target[i]] > 0){
                mpp[root][target[i]]--;
            }
            else{
                ans++;
            }
         
        }

        return ans;
    }
};
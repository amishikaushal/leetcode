class Solution {
public:
    vector<int> rank;
    vector<int>  parent;


    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;

        if(rank[py] > rank[px]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n + 1 , 0);

        parent.resize(n + 1);

        for(int i = 0 ; i <= n ; i++ ){
            parent[i] = i;
        }


        for(auto& it : edges){
            int u = it[0];
            int v = it[1];


            if(find(u) == find(v)){
                return it;
            }
            else{
                Union(u , v);
            }
        }

        return {};


    }
};
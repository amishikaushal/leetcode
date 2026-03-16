struct DisJoint{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJoint(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJoint ds(n * n);

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        // Step 1: connect all existing 1s
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 0) continue;

                for(int k = 0; k < 4; k++){
                    int newr = i + dr[k];
                    int newc = j + dc[k];

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int node = i*n + j;
                        int adj = newr*n + newc;

                        ds.unionByRank(node, adj);
                    }
                }
            }
        }

        int mx = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1) continue;

                set<int> components;

                for(int k = 0; k < 4; k++){
                    int newr = i + dr[k];
                    int newc = j + dc[k];

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        components.insert(ds.findParent(newr*n + newc));
                    }
                }

                int sizeTotal = 1; 

                for(auto comp : components){
                    sizeTotal += ds.size[comp];
                }

                mx = max(mx, sizeTotal);
            }
        }

        for(int cell = 0; cell < n*n; cell++){
            mx = max(mx, ds.size[ds.findParent(cell)]);
        }

        return mx;
    }
};
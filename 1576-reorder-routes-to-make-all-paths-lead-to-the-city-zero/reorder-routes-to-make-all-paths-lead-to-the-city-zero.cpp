class Solution {
public:
    void dfs(int node , vector<vector<pair<int , int>>> &adj , vector<int> &vis , int &changes){
        vis[node] = 1;

        for(auto &it : adj[node]){
            int nei = it.first;
            int cost = it.second;

            if(!vis[nei]){
                changes += cost;
                dfs(nei , adj , vis , changes);
            }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int , int>>> adj(n);

        for(auto &it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v , 1});
            adj[v].push_back({u , 0});
        }


        vector<int> vis(n , 0);
        int changes = 0;

        dfs(0 , adj , vis , changes);

        return changes;
    }
};
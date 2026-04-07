class Solution {
public:
    void dfs(int node , int parent , vector<vector<pair<int, int>>> &adj , vector<int> &diff , vector<int> &ans ){
        for(auto &[n , idx] : adj[node]){
            if(n == parent) continue;

            dfs(n , node , adj , diff , ans);
            if(diff[n] == 1){
                ans.push_back(idx);
                diff[n] ^= 1;
                diff[node] ^= 1;
            }
        }
    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int> diff(n);

        for(int i = 0; i < n ; i++){
            diff[i] = (start[i] - '0') ^ (target[i] - '0');
        }


        if(count(diff.begin() , diff.end() , 1) & 1) return {-1};
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v , i});
            adj[v].push_back({u , i});

        }
        vector<int> ans;


        dfs(0 , -1 , adj , diff , ans);
        sort(ans.begin() , ans.end());

        return ans;
        
    }
};
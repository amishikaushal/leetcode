class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);

        for(auto &it : paths){
            int u = it[0] - 1;
            int v = it[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> ans(n , 0);


        for(int i = 0; i < n ; i++){
            vector<int> used(5 , false);


            for(auto &it : adj[i]){
                used[ans[it]] = true;
            }


            for(int flower = 1 ; flower <= 4 ; flower++){
                if(!used[flower]){
                    ans[i] = flower;
                    break;
                }
            }
        }
        return ans;
      
    }
};
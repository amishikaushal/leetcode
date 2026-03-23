class Solution {
public:
    int timer = 1;
    void solve(int node , int parent , vector<int> &vis , vector<int> &tin , vector<int> &low , vector<vector<int>> &adj , vector<vector<int>> &ans){
        vis[node] = 1;
        low[node] = tin[node] = timer++;


        for(auto it : adj[node]){
            if(it == parent) continue;


            if(!vis[it]){
                solve(it , node , vis , tin , low , adj , ans);

                low[node] = min(low[node] , low[it]);

                if(low[it] > tin[node]){
                    ans.push_back({node , it});
                }
            }
            else{
                low[node] = min(low[node] , low[it]);
            }

        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> tin(n , -1);
        vector<int> low(n , -1);

        vector<int> vis(n , 0);
        vector<vector<int>> ans;



        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                solve(i , -1 , vis , tin , low , adj , ans);
            }
        }


        return ans;

    }
};
class Solution {
public:
    void dfs(int ind , vector<vector<int>>& stones , vector<int> &vis){
        vis[ind] = 1;

        for(int i = 0 ; i < stones.size() ; i++){
            if(!vis[i]){
                if(stones[i][0] == stones[ind][0] || stones[i][1] == stones[ind][1]){
                    dfs(i , stones , vis);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> vis(n , 0);
        int components = 0;

        for(int i = 0; i < n ; i++){
            if(!vis[i]){
                dfs(i ,  stones , vis);
                components++;
            }
        }

        return n - components;
    }
};
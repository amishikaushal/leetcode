class Solution {
public:
    vector<vector<int>> graph;
    int dfs(int root , int parent , vector<bool>& hasApple){
        int cost = 0;

        for(int child : graph[root]){
            if(child == parent) continue;

            int childCost = dfs(child , root , hasApple);

            if(childCost > 0 || hasApple[child]){
                cost += childCost + 2;
            }
        }
        return cost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);

        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);

        }

        return dfs(0 , -1 , hasApple);
        
    }
};
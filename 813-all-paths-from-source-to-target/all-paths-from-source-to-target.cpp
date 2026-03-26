class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(graph , 0 , ans , path);
        return ans;
    }

    void solve(vector<vector<int>>& graph , int node , vector<vector<int>>& ans , vector<int> &path){
        path.push_back(node);

        if(node == graph.size() - 1){
            ans.push_back(path);
        }
        else{
            for(auto &it : graph[node]){
                solve(graph , it , ans , path);
            }
        }

        path.pop_back();
    }
};
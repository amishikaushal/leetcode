class Solution {
public:
    void solve(vector<int>& candidates, int ind, int target , vector<int> &res , vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(res);
            }
            return;
        }

        if(candidates[ind] <= target){
            res.push_back(candidates[ind]);
            solve(candidates , ind , target - candidates[ind] , res , ans);

            res.pop_back();
        }

        solve(candidates , ind + 1 , target , res , ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> res;

        solve(candidates , 0 , target , res , ans);
        return ans;
    }
};
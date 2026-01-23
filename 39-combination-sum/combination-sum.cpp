class Solution {
public:
    void solve(int ind , vector<int>& candidates, int target , vector<int> &res, vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(res);
                
            }
            return;
        }

        if(candidates[ind] <= target){
            res.push_back(candidates[ind]);
            solve(ind  , candidates , target - candidates[ind] , res , ans);
            res.pop_back();
        }

        solve(ind + 1 , candidates , target  , res , ans);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;


        solve(0 , candidates , target , res , ans);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int>& candidates, int ind ,int target , vector<int> res , vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(res);
            return;
        }

        for(int i = ind ; i < candidates.size() ; i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;


            if(candidates[i] > target){
                break;
            }


            res.push_back(candidates[i]);

            solve(candidates , i + 1 , target - candidates[i] , res , ans);

            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;

        vector<int> res;

        solve(candidates , 0 , target , res , ans);
        return ans;



    }
};
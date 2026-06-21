class Solution {
public:
    void solve(vector<int>& nums , int ind , vector<int> res ,  vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[ind]);
        solve(nums ,ind + 1, res , ans);

        res.pop_back();
        solve( nums , ind + 1, res , ans);





    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;


        solve(nums , 0 , res , ans);

        return ans;
    }
};
class Solution {
public:
    void solve(int ind , vector<int>& nums, vector<vector<int>> &ans , vector<int> &res){
        if (ind == nums.size()) {
            ans.push_back(res);
            return;
        }

       
        res.push_back(nums[ind]);
        solve(ind + 1, nums, ans, res);
        res.pop_back(); // Backtrack

       
        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        solve(ind + 1, nums, ans, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;
        vector<int> res;

        solve(0 , nums , ans , res);

        return ans;


    }
};
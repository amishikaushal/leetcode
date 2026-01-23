class Solution {
public:
    void solve(int ind , vector<int>& nums, vector<vector<int>> &ans , vector<int> &res){
        int n = nums.size();

        ans.push_back(res);

        for(int i = ind ; i < n ; i++){

            if(i > ind && nums[i] == nums[i-1]) continue;


            res.push_back(nums[i]);
            solve(i +1 , nums , ans , res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;
        vector<int> res;

        solve(0 , nums , ans , res);

        return ans;


    }
};
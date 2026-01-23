class Solution {
public:
    void generate(int ind , vector<int>& nums , vector<int> res , vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[ind]);

        generate(ind + 1 , nums , res , ans);

        res.pop_back();
         generate(ind + 1 , nums , res , ans);



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> res;

        generate(0 , nums , res , ans);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = idx; i < nums.size(); i++)
        {
            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[idx], nums[i]);

            solve(idx + 1, nums);

            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        solve(0, nums);
        return ans;
    }
};
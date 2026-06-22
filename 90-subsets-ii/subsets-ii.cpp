class Solution {
public:
     vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx , vector<int> &nums){
        
         ans.push_back(curr);
            
        


        for(int i = idx ; i < nums.size() ; i++){
            if(i > idx && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);

            solve(i +1 , nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        solve(0 , nums);
        return ans;
    }
};
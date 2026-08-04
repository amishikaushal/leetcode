class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;


        unordered_set<int> seen(nums.begin() , nums.end());

        for(int i = 0; i < n ; i++){
            if(mini > nums[i]){
                mini = nums[i];
            }

            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }

        vector<int> ans;


        for(int i = mini ; i <= maxi; i++){
            if(!seen.count(i)){
                ans.push_back(i);
            }
        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for(auto x : nums){
            total += x;
        }

        int target = total % p;

        if (target == 0)
            return 0;       

        unordered_map<int , int> mpp;
        mpp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - target + p) % p;

            if(mpp.count(need)){
                ans = min(ans , i - mpp[need]);
            }

            mpp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
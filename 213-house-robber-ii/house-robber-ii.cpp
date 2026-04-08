class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();

        // 🔥 handle edge cases
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n , 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i = 2 ; i < n ; i++){
            int include = dp[i-2] + nums[i];
            int exclude = dp[i - 1];

            dp[i] = max(include , exclude);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> first(nums.begin() , nums.end() - 1);
        vector<int> second(nums.begin() + 1 , nums.end());

        return max(solve(first) , solve(second));
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for (int x : nums) totSum += x;


        if ((totSum + target) < 0 || (totSum + target) % 2 == 1) return 0;

        int s2 = (totSum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));


       if(nums[0] == 0) dp[0][0] = 2;
       else dp[0][0] = 1;

       if(nums[0] != 0 && nums[0] <= s2) dp[0][nums[0]] = 1;

       
        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= s2; tar++) {
                int notTake = dp[i-1][tar];
                int take = 0;
                if (nums[i] <= tar) {
                    take = dp[i-1][tar - nums[i]];
                }
                dp[i][tar] = take + notTake;
            }
        }

        return dp[n-1][s2];
    }
};

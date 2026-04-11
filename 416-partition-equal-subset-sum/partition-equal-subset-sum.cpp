class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin() , nums.end() , 0);

        if(total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<bool>> dp(n + 1 , vector<bool>(target + 1 , false));
        for(int i = 0; i <= n ; i++){
            dp[i][0] = true;

        }

        for(int i = 1 ; i <= n ; i++){
            for(int t = 1 ; t <= target ; t++){
                bool notTake = dp[i-1][t];

                bool take = false;
                if(nums[i-1] <= t){
                    take = dp[i-1][t-nums[i-1]];
                } 

                dp[i][t] = take || notTake;
            }

        }
        return dp[n][target];

    }
};
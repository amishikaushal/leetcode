class Solution {
public:
    int dp[505][505][3];

    int solve(int i, int j, int k, vector<vector<int>>& coins, int m, int n) {
        
        if(i >= m || j >= n) return INT_MIN;

        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && k > 0) return 0;
            return coins[i][j];
        }

        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int val = coins[i][j];

        int down = solve(i+1, j, k, coins, m, n);
        int right = solve(i, j+1, k, coins, m, n);

        int bestNext = max(down, right);

        int ans = INT_MIN;

        if(bestNext != INT_MIN){
            ans = val + bestNext;
        }

        // skip
        if(val < 0 && k > 0){
            int downSkip = solve(i+1, j, k-1, coins, m, n);
            int rightSkip = solve(i, j+1, k-1, coins, m, n);

            int bestSkip = max(downSkip, rightSkip);

            if(bestSkip != INT_MIN){
                ans = max(ans, bestSkip);
            }
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();

        // initialize with INT_MIN
        for(int i=0;i<505;i++)
            for(int j=0;j<505;j++)
                for(int k=0;k<3;k++)
                    dp[i][j][k] = INT_MIN;

        return solve(0, 0, 2, coins, m, n);
    }
};
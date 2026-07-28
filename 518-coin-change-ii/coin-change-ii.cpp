class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();

        vector<vector<int>> dp(m , vector<int>(amount + 1 , 0));


        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }


        for(int i = 0 ; i <= amount ; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
        }


        for(int i = 1; i < coins.size() ; i++){
            for(int t = 1; t <= amount ; t++){
                unsigned int nottake = dp[i-1][t];

                unsigned int take = 0;
                if(coins[i] <= t){
                    take = dp[i][t - coins[i]];
                }


                dp[i][t] = take + nottake;
            }
        
        }

        return dp[m-1][amount];
    
    }
};
class Solution {
public:
    /*int solve(int ind , int buy , int cap , vector<int>& prices ,vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || cap == 0){
            return 0;
        }


        if(dp[ind][buy][cap] != -1){
            return dp[ind][buy][cap];
        }
        int profit = 0;

        if(buy){
            int ignore = solve(ind + 1 , 1 , cap , prices , dp);
            int buyKaro = -prices[ind] + solve(ind + 1 , 0 , cap , prices , dp );


            profit = max(ignore , buyKaro);
        }
        else{
            int ignore = solve(ind + 1 , 0 , cap , prices , dp);
            int buyKaro = prices[ind] + solve(ind + 1 , 1 , cap - 1, prices , dp );


            profit = max(ignore , buyKaro);

        }

        return dp[ind][buy][cap] = profit;
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(3 , 0)));


        int profit = 0;

        for(int i = n -1  ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap <= 2 ; cap++){
                    if(buy == 0){
                        dp[i][buy][cap] = max(dp[i + 1][0][cap] , prices[i] + dp[i + 1][1][cap - 1]);
                    }
                    else{
                        dp[i][buy][cap] = max(dp[i+1][1][cap] , -prices[i] + dp[i+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
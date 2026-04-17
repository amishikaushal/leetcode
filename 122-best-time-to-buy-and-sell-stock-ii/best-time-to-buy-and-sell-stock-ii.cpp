class Solution {
public:
    /*int solve(int ind , int buy , vector<int>& prices ,vector<vector<int>> &dp){
        if(ind == prices.size()){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        int profit = 0;
        if(buy){
             int buyKaro = -prices[ind] + solve(ind + 1 , 0 , prices , dp);
            int ignoreKaro = 0 + solve(ind + 1 , 1 , prices , dp);

            profit = max(buyKaro , ignoreKaro);
        }

        else{
            int sellKaro = prices[ind] + solve(ind + 1 , 1 , prices , dp);
            int ignoreKaro = 0 + solve(ind + 1 , 0 , prices , dp);

            profit = max(sellKaro , ignoreKaro );
        }


        return dp[ind][buy] = profit;
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1 , vector<int>(2 , 0));

        for(int ind = n -1 ; ind >= 0 ; ind--){
            for(int buy = 0; buy <= 1 ; buy++){
                int profit = 0;

                if(buy){
                    int buyKaro = dp[ind + 1][1];
                    int ignoreKaro = -prices[ind] + dp[ind + 1][0];

                    profit = max(buyKaro , ignoreKaro);
                }
                else{
                    int buyKaro = dp[ind + 1][0];
                    int ignoreKaro = prices[ind] + dp[ind + 1][1];

                    profit = max(buyKaro , ignoreKaro);
                }


                dp[ind][buy] = profit;
            }
        }


        return dp[0][1];
    }
};
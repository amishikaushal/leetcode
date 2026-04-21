class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> curr(2 , 0);
        vector<int> next(2 , 0);


        int profit = 0;


        for(int i = n -1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){

                if(buy == 1){
                    int ignore = 0 + next[1];

                    int buyKaro = -prices[i] + next[0];

                    profit = max(ignore , buyKaro);
                }
                else{
                    int ignore = 0 + next[0];

                    int sell = prices[i] - fee + next[1];

                    profit = max(ignore , sell);
                }

                 curr[buy] = profit;
                
            }

            next = curr;
        }

        return next[1];

        
    }
};
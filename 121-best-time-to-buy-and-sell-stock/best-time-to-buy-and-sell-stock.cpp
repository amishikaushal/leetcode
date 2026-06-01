class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;

        int mini = prices[0];

        for(int i = 1 ; i < n ; i++){
            int diff = prices[i] - mini;

            if(diff > maxi){
                maxi = diff;
            }

            mini = min(prices[i] , mini);
        }

        return maxi;
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remain = ans;

        while(remain >= numExchange){
            remain -= numExchange;

            ans++;

            remain++;
        }

        return ans;
    }
};
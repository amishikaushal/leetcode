class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;


        while(numBottles >= numExchange){
            int add = numBottles / numExchange;

            int rem = numBottles % numExchange;

            ans += add;

            numBottles = rem + add;
        }
        return ans;
    }
};
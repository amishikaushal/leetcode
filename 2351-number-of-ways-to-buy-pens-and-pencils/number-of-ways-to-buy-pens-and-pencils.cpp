class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;

        int maxPencils = total / cost2;

        for (int i = 0; i <= maxPencils; i++) {
            long long moneyLeft = total - 1LL * i * cost2;
            long long maxPens = moneyLeft / cost1;
            ways += (maxPens + 1);
        }

        return ways;
    }
};
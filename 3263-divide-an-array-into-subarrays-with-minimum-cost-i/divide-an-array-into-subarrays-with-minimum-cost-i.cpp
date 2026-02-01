class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int total = nums[0];

        sort(nums.begin() + 1 , nums.end());


        total += nums[1];
        total += nums[2];


        return total;
    }
};
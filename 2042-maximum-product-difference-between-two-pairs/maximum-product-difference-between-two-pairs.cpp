class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int f = nums[0];
        int s = nums[1];

        int la = nums[n-1];
        int sl = nums[n-2];

        int maxi = la * sl;
        int mini = f * s;

        return maxi - mini;
    }
};
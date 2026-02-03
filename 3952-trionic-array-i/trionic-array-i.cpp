class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
        if (n < 4) return false;

        int i = 0, p = 0, q = 0;

        while (i < n - 1 && nums[i + 1] > nums[i])
            i++;
        p = i;
        if (p == 0) return false;


        while (i < n - 1 && nums[i + 1] < nums[i])
            i++;
        q = i;
        if (q == p || q == n -1) return false;

    
        while (i < n - 1 && nums[i + 1] > nums[i])
            i++;

        return i == n - 1;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int totalXor = 0;
        bool isfalse = false;

        for(int n : nums){
            if(n != 0){
                isfalse = true;
            }

            totalXor ^= n;
        }


        if(totalXor != 0){
            return n;
        }

        if(isfalse){
            return n-1;
        }

        return 0;
    }
};
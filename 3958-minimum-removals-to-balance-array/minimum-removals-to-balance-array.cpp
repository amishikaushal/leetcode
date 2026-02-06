class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int i = 0 ;
        int j = 0;
        int maxLen = 0;


        while(j < n){
            while (i <= j && nums[j] > (long long)k * nums[i]) {
                i++;
            }

            maxLen = max(maxLen , j - i + 1);

            j++;


        }

        return n - maxLen;
    }
};
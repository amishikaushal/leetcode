class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        mpp[0] = 1;

        int prefix = 0;
        int ans = 0;


        for(int i = 0; i < n ; i++){
            prefix += nums[i];

            int remain = prefix -k;


            ans += mpp[remain];

            mpp[prefix]++;

        }

        return ans;
    }
};
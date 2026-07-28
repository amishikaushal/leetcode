class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<int> dp(n , 1);

        vector<int> hash(n);

        for(int i = 0; i < n ; i++){
            hash[i] = i;

            for(int prev = 0; prev < i ; prev++){

                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){
                    dp[i] = 1 + dp[prev];

                    hash[i] = prev;
                }
            }
        }

        vector<int> ans;

        int an = dp[0]; 
        int last = 0;

        for(int i = 1; i < n ; i++){
            if(dp[i] > an){
                an = dp[i];
                last = i;
            }
        }


        while(hash[last] != last){
            ans.push_back(nums[last]);
            last = hash[last];
        }

        ans.push_back(nums[last]);

        reverse(ans.begin() , ans.end());

        return ans;
    }
};
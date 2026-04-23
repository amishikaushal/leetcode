class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<int> dp(n , 0);
        vector<int> hash(n);

        for(int i = 0; i < n ; i++){
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }

        int an = -1; 
        int last = -1;

        for(int i = 0; i < n ; i++){
            if(dp[i] > an){
                an = dp[i];
                last = i;
            }
        }


        vector<int> ans;

        ans.push_back(nums[last]);


        while(hash[last] != last){
            last = hash[last];
            ans.push_back(nums[last]);
        }


        reverse(ans.begin() , ans.end());

        return ans;
    }
};
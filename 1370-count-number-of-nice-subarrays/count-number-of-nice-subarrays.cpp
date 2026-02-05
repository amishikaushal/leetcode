class Solution {
public:
    int solve(vector<int>& nums , int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int odd = 0;

        int cnt = 0;
        while(r < n){
            if(nums[r] % 2 == 1){
                odd++;
            }


            while(odd > k){
                if(nums[l] % 2 == 1){
                    odd--;
                }
                l++;
            }


            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k ) - solve(nums , k-1);
    }
};
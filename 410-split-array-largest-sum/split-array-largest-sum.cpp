class Solution {
public:
    int cnt(vector<int>& nums, int maxSum){
        int cnt = 1;
        long long currSum = 0;

        for(int num : nums){
            if(currSum + num <= maxSum){
                currSum += num;
            }
            else{
                cnt++;
                currSum = num;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin() , nums.end());
        int h = accumulate(nums.begin() , nums.end(), 0);

        while(l <= h){
            int mid = l + (h - l)/2;

            if(cnt(nums , mid) <= k){
                
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
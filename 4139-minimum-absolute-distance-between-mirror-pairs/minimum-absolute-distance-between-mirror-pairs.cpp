class Solution {
public:
    int rev(int x){
        int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int , int> mpp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size() ; i++){
            if(mpp.count(nums[i])){
                ans = min(ans , i - mpp[nums[i]]);
            }


            int reverse = rev(nums[i]);
            mpp[reverse] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
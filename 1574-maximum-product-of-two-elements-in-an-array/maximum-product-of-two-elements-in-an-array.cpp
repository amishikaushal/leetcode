class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size() ; i++){
            for(int j = i +1 ; j < nums.size() ;j++){
                int a = nums[i];
                int b = nums[j];

                maxi = max(maxi , (a - 1) * (b-1));
            }
        }
        return maxi;

    }
};
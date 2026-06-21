class Solution {
public:
    int solve(vector<int>& nums , int ind , int curr){
        if(ind == nums.size()){
            return curr;
        }
        int with = solve(nums , ind + 1 , curr ^ nums[ind]);
        int without = solve(nums , ind + 1 , curr);


        return with + without;


    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums , 0 , 0);
    }
};
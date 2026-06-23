class Solution {
public:

    bool solve(int ind , vector<int>& matchsticks , vector<int>& sides , int target){
        if(ind == matchsticks.size()){
            for(auto &s : sides){
                if(s != target){
                    return false;
                }
            }
            return true;
        }

        for(int i = 0; i < sides.size() ; i++){

            if(sides[i] + matchsticks[ind] > target){
                continue;
            }

            sides[i] += matchsticks[ind];

            if(solve(ind + 1 , matchsticks , sides , target)){
                return true;
            }


            sides[i] -= matchsticks[ind];

              if (sides[i] == 0)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin() , nums.end() , 0);


        if(sum % k != 0){
            return false;
        }

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target){
            return false;
        }
        vector<int> bucket(k , 0);

        return solve(0 , nums , bucket,  target);
    }
};
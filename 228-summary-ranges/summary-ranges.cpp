class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if(nums.size() == 0) return result;

        int start = nums[0];

        for(int i = 1 ; i <= nums.size() ; i++){
            if(i == nums.size() || nums[i] != nums[i-1] + 1) {

                int end = nums[i-1];

                if(start == end) {
                    result.push_back(to_string(start));
                } 
                else {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }

             
                if(i < nums.size())
                    start = nums[i];
            }
        }
        return result;
    }
};
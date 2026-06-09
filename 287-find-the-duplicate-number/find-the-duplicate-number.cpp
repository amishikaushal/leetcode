class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(auto &it : nums){
            if(seen.count(it)){
                return it;
            }

            seen.insert(it);
        }

        return -1;
    }
};
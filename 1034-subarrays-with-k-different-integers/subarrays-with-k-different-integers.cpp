class Solution {
public:
    int kDistinctChar(vector<int>& s, int k) {
       int n = s.size();

       int l = 0;
       int r = 0;
       unordered_map< int , int> mpp;
       
       int maxLen = 0;

       while(r < n){
            mpp[s[r]]++;

            while(mpp.size() > k){
                mpp[s[l]]--;

                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }

                l++;
            }

            maxLen += (r - l + 1);

            r++;
       }
       return maxLen;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kDistinctChar(nums , k) - kDistinctChar(nums , k -1);
    }
};
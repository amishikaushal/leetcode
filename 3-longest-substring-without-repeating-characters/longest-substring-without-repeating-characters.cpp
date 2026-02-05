class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mpp;

        int l = 0;
        int r = 0;

        int maxi = 0;
        int n = s.length();


        while(r < n){
            while(mpp.count(s[r])){
                mpp.erase(s[l]);
                l++;
            }

            mpp.insert(s[r]);
            maxi = max(maxi , r - l + 1);

            r++;
        }

        return maxi;
    }
};
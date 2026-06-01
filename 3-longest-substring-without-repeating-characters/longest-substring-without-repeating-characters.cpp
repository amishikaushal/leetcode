class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        int n = s.length();

        int maxi = 0;
        unordered_set<char> seen;

        while(r < n){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            maxi = max(maxi , r - l +1);

            r++;
        }
        return maxi;

    }
};
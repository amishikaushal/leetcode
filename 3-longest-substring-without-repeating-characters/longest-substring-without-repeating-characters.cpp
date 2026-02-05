class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.length();
        int ans = 0;
        int l = 0;
        int r = 0;

        while(r < n){
            if(!seen.count(s[r])){
                seen.insert(s[r]);

                ans = max(ans , r - l + 1);
                r++;
            }
            else{
                seen.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};
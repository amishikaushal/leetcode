class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }
        int n = s.length();
        int m = t.length();

        unordered_map<char , int> mpp;
        unordered_map<char , int> freq;


        for(auto ch : t){
            mpp[ch]++;
        }

        int needed = mpp.size();

        int match = 0;
        int minLen = INT_MAX;
        int start = 0;


        int l = 0;
        int r = 0;


        while(r < n){
            freq[s[r]]++;

            char ch = s[r];

            if(mpp.count(ch) && freq[ch] == mpp[ch]){
                match++;
            }

            while(match == needed){
                int len = r - l + 1;

                if(len < minLen){
                    start = l;
                    minLen = len;
                }

                freq[s[l]]--;
                if(mpp.count(s[l]) && mpp[s[l]] > freq[s[l]]){
                    match--;
                }
                l++;
            }
            r++;

        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);

    }
};
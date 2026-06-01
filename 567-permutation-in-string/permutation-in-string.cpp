class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int k = s1.length();

        unordered_map<char , int> mpp;

        for(auto &it : s1){
            mpp[it]++;
        }

        int needed = mpp.size();

        unordered_map<char , int> window;
        int match = 0;

        int l = 0;
        int r = 0;

        while(r < n){
            window[s2[r]]++;
            char ch = s2[r];

            if(mpp.count(ch) && mpp[ch] == window[ch]){
                match++;
            }

            while(r - l + 1 > k){
                char c = s2[l];
                if(mpp.count(c) && mpp[c] == window[c]){
                    match--;
                }

                window[c]--;
                l++;
            }

            if(needed == match && r - l + 1 == k){
                return true;
            }
            r++;
        }
        return false;
    }
};
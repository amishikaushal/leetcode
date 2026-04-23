class Solution {
public:
    bool compare(string &s1 , string &s2){
        if(s1.length() != s2.length() + 1) return false;

        int i = 0, j = 0;
        while (i < s1.length()) {
            if (j < s2.length() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == s2.size();


    }
    static bool comp(const string &a, const string &b) {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<int> dp(n , 1);

        sort(words.begin(), words.end(), comp);
        int maxi = 1;

        for(int i = 0; i < n ; i++){
            for(int prev = 0; prev < i ; prev++){
                if(compare(words[i] , words[prev]) && 1 + dp[prev] > dp[i]){

                    dp[i] = 1 + dp[prev];

                }
            }

            maxi = max(maxi , dp[i]);
        }
        return maxi;

    }
};
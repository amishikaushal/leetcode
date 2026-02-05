class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;

        int maxf = 0;
        unordered_map<char , int> mpp;
        int maxi = 0;


        while(r < n){
            mpp[s[r]]++;

            maxf = max(maxf , mpp[s[r]]);

            while(r - l + 1 - maxf > k){
                mpp[s[l]]--;

                for(auto it : mpp){
                    maxf = max(maxf , it.second);
                }

                l++;

            }


            maxi = max(maxi , r - l + 1);

            r++;
        }

        return maxi;
    }
};
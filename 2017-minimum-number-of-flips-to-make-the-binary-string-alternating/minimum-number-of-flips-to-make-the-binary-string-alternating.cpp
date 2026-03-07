class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        int diff1 = 0, diff2 = 0;
        int l = 0;
        int ans = INT_MAX;

        for(int r = 0; r < 2*n; r++) {

            char expected1 = (r % 2) ? '1' : '0';
            char expected2 = (r % 2) ? '0' : '1';

            if(ss[r] != expected1) diff1++;
            if(ss[r] != expected2) diff2++;

            if(r - l + 1 > n) {

                char leftExpected1 = (l % 2) ? '1' : '0';
                char leftExpected2 = (l % 2) ? '0' : '1';

                if(ss[l] != leftExpected1) diff1--;
                if(ss[l] != leftExpected2) diff2--;

                l++;
            }

            if(r - l + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};
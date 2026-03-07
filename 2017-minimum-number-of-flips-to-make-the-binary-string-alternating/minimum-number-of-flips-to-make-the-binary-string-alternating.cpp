class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        string ss = s + s;
        string alt1 = "";
        string alt2 = "";

        for(int i = 0 ; i < 2 * n ;i++){
            if(i % 2 == 0){
                alt1 += '0';
                alt2 += '1';
            }
            else{
                alt1 += '1';
                alt2 += '0';
            }
        }


        int diff1 = 0; 
        int diff2 = 0;
        int ans = INT_MAX;
        int l = 0;


        for(int r = 0; r < 2 * n ; r++){
            if(ss[r] != alt1[r]) diff1++;
             if(ss[r] != alt2[r]) diff2++;


             if(r - l + 1 > n){
                if(ss[l] != alt1[l]) diff1--;
                if(ss[l] != alt2[l]) diff2--;

                l++;
             }

             if(r - l + 1 == n){
                ans = min(ans , min(diff1 , diff2));
             }

        }

        return ans;

    }
};
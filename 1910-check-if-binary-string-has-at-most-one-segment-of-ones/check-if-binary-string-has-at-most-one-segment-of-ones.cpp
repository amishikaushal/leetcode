class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        int n = s.length();

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')){
                cnt++;
            }
        }

        return cnt == 1;
    }
};
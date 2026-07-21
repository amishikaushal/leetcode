/*
    int solve(int i , string s){
        if(i == n ){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        int ways = 0;

        ways += solve(i + 1 , s);

        if(i + 1 < s.size()){
            int num = s[i] * 10 + s[i+1] - '0';


            if(num >= 10 && num <= 26){

                ways += solve(i + 2 , s);
            }
        }
        return ways;
    }



-------------------------------------------------------------------------------
     if(i == n){
        return 1;
    }

    if(s[i] == '0'){
        return 0;
    }

    int ways = 0;

    ways += solve(i + 1 , s);

    if(i + 1 < s.size()){
        int num = s[i] * 10 + s[i+1] - 'a';

        if(num >= 10 && nums <= 26){
            ways += solve(i + 2 , s);
        }
    }

    return ways;
*/
    


class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n+1 , 0);

        dp[n] = 1;

        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1];

                if(i +1 < n){
                    int num = (s[i] - '0' )* 10 + (s[i+1] - '0');

                    if(num >= 10 && num <= 26){
                        dp[i] += dp[i+2];
                    }
                }
            }
           
        }
        return dp[0];

        /*int next1 = 1;
        int next2 = 0;

        for(int i = n -1 ; i >= 0 ; i--){
            int curr = 0;
        

            if(s[i] != '0'){
                curr = next1;

                if(i + 1 < n ){
                    int num = (s[i] - '0')*10 + (s[i + 1] - '0');

                    if(num >= 10 && num <= 26){
                        curr += next2;
                    } 
                }
            }

            next2 = next1;
            next1 = curr;
        }
        return next1;*/
    }
};
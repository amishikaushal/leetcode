class Solution {
public:
    bool isPalindrome(int si , int e , string &s){
        while(si < e){
            if(s[si] != s[e]){
                return false;
            }

            si++;
            e--;

        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();

    
        vector<int> dp(n +1 , 0);

        dp[n] = 0;




        for(int i = n -1 ; i >= 0 ; i--){
            int minCost = INT_MAX;
            for(int j = i ; j < n ; j++){
                if(isPalindrome(i , j , s)){
                     
                    minCost = min(minCost , 1 + dp[j+1]);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;

    }
};
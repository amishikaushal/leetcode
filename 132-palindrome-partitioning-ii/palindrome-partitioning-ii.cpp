class Solution {
public:
    bool isPalindrome(string &a , int s , int e){
        while(s < e){
            if(a[s] != a[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n + 1 , 0);
        


        for(int i = n -1 ; i >= 0; i--){
            int cost = INT_MAX;

            for(int j = i ; j < n ; j++){
                if(isPalindrome(s , i , j)){
                    cost = min(cost , 1 + dp[j+1]);
                }
            }

            dp[i] = cost;
        }
        return dp[0] - 1;

    }
};
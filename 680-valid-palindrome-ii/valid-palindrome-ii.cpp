class Solution {
public:
    bool isValid(string s , int l , int r){
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        
        int l = 0;

        int r = n-1;

        while(l <= r){
            if(s[l] != s[r]){
               return isValid(s , l + 1 , r) || isValid(s , l , r-1); 
            }
            l++;
            r--;
        }
        return true;
    }
};
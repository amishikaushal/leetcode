class Solution {
public:
    bool isPalindrome(string s , int st , int e){
        while(st <= e){
            if(s[st++] != s[e--]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind , string s, vector<string> res,  vector<vector<string>> &ans){
        if(ind == s.length()){
            ans.push_back(res);
            return;
        }

        for(int i = ind ; i < s.length() ; i++){
            if(isPalindrome(s , ind , i)){
                res.push_back(s.substr(ind , i - ind + 1));
                solve(i + 1 , s , res , ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;

        solve(0 , s , res , ans);
        return ans;
    }
};
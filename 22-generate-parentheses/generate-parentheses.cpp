class Solution {
public:
    void solve(int even , int odd , string &curr , vector<string> &ans){
        if(even == 0 && odd == 0){
            ans.push_back(curr);
            return;
        }


        if(even > 0){
            string op1 = curr;
            op1.push_back('(');

            solve(even - 1 , odd , op1 , ans);
        }
        if(odd > even){
            string op2 = curr;
            op2.push_back(')');
            solve(even , odd - 1 , op2 , ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int odd = n ; 
        int even = n;

        vector<string> ans;
        string curr = "";

        solve(even , odd , curr , ans);

        return ans;

    }
};
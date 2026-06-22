class Solution {
public:
    vector<string> ans;
    void solve(int even , int odd , string &curr){
        if(even == 0 && odd == 0){
            ans.push_back(curr);
            return;
        }


        if(even > 0){
            string op1 = curr;

            op1.push_back('(');

            solve(even -1 , odd , op1);
        }


        if(odd > even){
            string op2 = curr;

            op2.push_back(')');

            solve(even , odd -1 , op2);
        }
    }
    vector<string> generateParenthesis(int n) {
        int even = n;
        int odd = n;
        string curr = "";

        solve(even , odd , curr);

        return ans;
    }
};
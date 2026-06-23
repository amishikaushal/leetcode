class Solution {
public:
    vector<string> ans;
    unordered_map<char , string> mpp = {{'2' , "abc"} , {'3', "def"} ,  {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}; 

    void solve(int ind , string digits, string &path){
        if(ind == digits.size()){
            ans.push_back(path);
            return;
        }

        string letter = mpp[digits[ind]];

        for(auto ch : letter){
            path.push_back(ch);

            solve(ind + 1 , digits , path);

            path.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        string path = "";

        solve(0 , digits , path);

        return ans;

        
    }
};
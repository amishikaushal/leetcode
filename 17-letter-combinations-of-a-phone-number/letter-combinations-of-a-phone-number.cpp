class Solution {
public:
    vector<string> result;
    unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void solve(int ind , string& path , string& digits ){
        if(ind == digits.size()){
            result.push_back(path);
            return;
        }

        string letters = phoneMap[digits[ind]];
        for (char ch : letters) {
            path.push_back(ch);
            solve(ind + 1, path, digits);
            path.pop_back(); 
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string path = "";
        solve(0, path, digits);
        return result;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string token;
        vector<string> ans;


        while(ss >> token){
            ans.push_back(token);
        }


        return ans.back().length();
    }
};
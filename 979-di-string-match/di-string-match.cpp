class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();

        int l = 0 , h = n;
        vector<int> ans;


        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'I'){
                ans.push_back(l++);
            }
            else{
                ans.push_back(h--);
            }
        }

        ans.push_back(l);
        return ans;
    }
};
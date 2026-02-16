class Solution {
public:
    string combine(string s1 , string s2){
        if(s1.find(s2) != string::npos) return s1;
        if (s2.find(s1) != string::npos) return s2;


        int n1 = s1.size();
        int n2 = s2.size();

        for(int k = min(n1 , n2) ; k >= 0 ; k--){
            if(s1.substr(n1- k) == s2.substr(0 , k)){
                return s1 + s2.substr(k);
            }
        }


        return s1 + s2;
    }
    string minimumString(string a, string b, string c) {
        vector<string> candidates;
        
        candidates.push_back(combine(combine(a,b),c));
        candidates.push_back(combine(combine(a,c),b));
        candidates.push_back(combine(combine(b,a),c));
        candidates.push_back(combine(combine(b,c),a));
        candidates.push_back(combine(combine(c,a),b));
        candidates.push_back(combine(combine(c,b),a));



        string ans = candidates[0];

        for (auto &s : candidates) {
            if (s.size() < ans.size() || 
               (s.size() == ans.size() && s < ans)) {
                ans = s;
            }
        }
        
        return ans;
    }
};
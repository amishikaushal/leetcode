class Solution {
public:
    string reverseOnlyLetters(string s) {
       

       string let;

       for(auto c : s){
            if(isalpha(c)){
                let += c;
            }
        }

        int ind = let.length() - 1;

        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                s[i] = let[ind--];
            }
        
        
        }
        return s;

       
    }
};
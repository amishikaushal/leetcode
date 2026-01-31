class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = target - 'a';

        for(auto it : letters){
            int m = it - 'a';

            if(m > n){
                return it;
                
            }
        }

        return letters[0];
    }
};
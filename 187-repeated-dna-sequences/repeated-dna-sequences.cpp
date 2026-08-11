class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> ans;

        if(s.size() < 10 ){
            return ans;
        }


        for(int i = 0; i <= s.size() - 10; i++){
            string curr = s.substr(i , 10);


            freq[curr]++;

            if(freq[curr] == 2){
                ans.push_back(curr);
            }
        }
        return ans;

     
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();

        unordered_map<int , int> mpp;
        for(int i = 0; i < n ; i++){
            mpp[tasks[i]]++;
        }

        int rounds = 0;


        for(auto &it : mpp){
            if(it.second == 1){
                return -1;
            }
            else if(it.second % 3 == 0){
                rounds += it.second / 3;

            }
            else{
                rounds += it.second / 3 + 1;
            }
        }

        return rounds;
    }
};
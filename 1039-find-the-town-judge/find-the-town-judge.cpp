class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1 , 0);
        vector<int> trusted(n + 1 , 0);


        for(auto &it : trust){
            int a = it[0];
            int b = it[1];

            trusts[a]++;
            trusted[b]++;
        }


        for(int i = 1 ; i <= n ; i++){
            if(trusts[i] == 0 && trusted[i] == n -1){
                return i;
            }
        }

        return -1;
    }
};
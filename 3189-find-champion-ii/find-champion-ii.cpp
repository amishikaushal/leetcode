class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n , 0);

        for(auto &it : edges){
            int from = it[0];
            int to = it[1];

            indegree[to]++;
        }



        int cnt = 0;
        int ans = -1;


        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                cnt++;
                ans = i;
            }
        }

        if(cnt > 1){
            return -1;
        }


        return ans;
    }
};
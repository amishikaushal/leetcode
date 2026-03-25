class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n , 0);
        set<pair <int , int>> connected;


        for(auto &it : roads){
            int a = it[0];
            int b = it[1];

            degree[a]++;
            degree[b]++;

            connected.insert({a , b});
            connected.insert({b , a});
        }
        int maxRank = 0;


        for(int i = 0; i < n ; i++){
            for(int j = i +1 ; j < n ; j++){
                int rank = degree[i] + degree[j];

                if(connected.count({i, j})){
                    rank--;
                }


                maxRank = max(maxRank , rank);
            }
        }

        return maxRank;
    }
};
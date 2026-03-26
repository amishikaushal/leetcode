class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n , 0);

        for(auto &it : roads){
            int a = it[0];
            int b = it[1];

            degree[a]++;
            degree[b]++;
        }

        vector<pair<int , int>> nodes;
        for(int i = 0 ; i < n ; i++){
            nodes.push_back({degree[i] , i});

        }


        sort(nodes.begin() , nodes.end());

        vector<int> rank(n);
        for(int i = 0; i < n ; i++){
            rank[nodes[i].second] = i + 1;
        }

        long long sum = 0;

        for(auto &it : roads){
            sum += rank[it[0]] + rank[it[1]];
        }

        return sum;


       
    }
};
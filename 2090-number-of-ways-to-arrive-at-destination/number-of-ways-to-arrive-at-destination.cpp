class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> adj(n);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];


            adj[u].push_back({v , time});
            adj[v].push_back({u , time});

        }

        vector<int> ways(n , 0);
        vector<long long > dist(n , LLONG_MAX);


        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;


 

        dist[0] = 0;
        pq.push({0 , 0});
        ways[0] = 1;


        while(!pq.empty()){
            auto [dis , node] = pq.top();
            pq.pop();


            for(auto it : adj[node]){
                int cost = it.second;
                int nei = it.first;

                if(cost + dis < dist[nei]){
                    dist[nei] = cost + dis;
                    ways[nei] = ways[node];

                    pq.push({dist[nei] , nei});
                }
                else if(cost + dis == dist[nei]){
                    ways[nei] = (ways[node] + ways[nei]) % MOD;
                }
            }
        }

        


        return ways[n-1];


    }
};
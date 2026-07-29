class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);


        for(auto it : times){
            int to = it[0];
            int from = it[1];
            int cost = it[2];

            adj[to].push_back({from , cost});

        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;

        pq.push({0 , k});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            for(auto it : adj[node]){
                int cost = it.second;
                int nei = it.first;

                if(cost +  dis < dist[nei]){
                    dist[nei] = cost +  dis;
                    pq.push({dist[nei] , nei});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxi = max(maxi , dist[i]);
        }
        return maxi;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        vector<vector<pair<int , int>>> adj(n);

        for(auto it : flights){
            int from = it[0];
            int to = it[1];
            int price = it[2];

            adj[from].push_back({to , price});
        }


        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<int> dist(n , 1e9);

        dist[src] = 0;
        pq.push({0 , {src , 0}});

        while(!pq.empty()){
            int steps = pq.top().first;
            int node = pq.top().second.first;
            int dis = pq.top().second.second;

            pq.pop();

            if(steps > k){
                continue;
            }

            for(auto it : adj[node]){
                int nei = it.first;
                int cost = it.second;

                if(dist[nei] > cost + dis){
                    dist[nei] = cost + dis;

                    pq.push({steps +1 , {nei , dist[nei]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];


    }
};
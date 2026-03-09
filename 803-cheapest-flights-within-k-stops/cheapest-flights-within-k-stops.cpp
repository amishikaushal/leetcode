class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);

        for (auto it : flights) {
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to , price});
        }

     
        priority_queue<pair<int , pair<int , int>>,
                       vector<pair<int , pair<int , int>>>,
                       greater<pair<int , pair<int , int>>>> pq;

        pq.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!pq.empty()) {
            auto itt = pq.top();
            pq.pop();

            int steps = itt.first;
            int node  = itt.second.first;
            int cost  = itt.second.second;

            if (steps > k) continue;

            for (auto neigh : adj[node]) {
                int nextNode = neigh.first;
                int wt = neigh.second;

                if (cost + wt < dist[nextNode]) {
                    dist[nextNode] = cost + wt;
                    pq.push({steps + 1, {nextNode, dist[nextNode]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

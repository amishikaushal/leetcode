class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n);
        for (int i = 0; i < n; i++) dist[i] = i;

        vector<vector<int>> adj(n);
        
        // initial edges
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];
            adj[u].push_back(v);

            queue<int> qu;

            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                qu.push(v);

                while (!qu.empty()) {
                    int node = qu.front(); 
                    qu.pop();

                    for (int nei : adj[node]) {
                        if (dist[node] + 1 < dist[nei]) {
                            dist[nei] = dist[node] + 1;
                            qu.push(nei);
                        }
                    }
                }
            }

            ans.push_back(dist[n - 1]);
        }

        return ans;
        
    }
};
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);

     
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            vector<int> neighbors;

            
            for (auto &nbr : adj[i]) {
                neighbors.push_back(vals[nbr]);
            }

            sort(neighbors.begin(), neighbors.end(), greater<int>());

            int sum = vals[i];

            for (int j = 0; j < min(k, (int)neighbors.size()); j++) {
                if (neighbors[j] > 0)
                    sum += neighbors[j];
                else
                    break;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
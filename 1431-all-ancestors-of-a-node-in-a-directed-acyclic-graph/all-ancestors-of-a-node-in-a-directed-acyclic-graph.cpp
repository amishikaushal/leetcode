class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
          
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        

        vector<set<int>> ancestors(n);
        

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                
     
                ancestors[v].insert(u);
                
   
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
                
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        
       
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return result;
    }
};
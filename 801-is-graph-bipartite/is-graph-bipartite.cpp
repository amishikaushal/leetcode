class Solution {
public:
    bool solve(int node, vector<vector<int>>& graph , vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nei : graph[node]){
                if(color[nei] == 0){
                    color[nei] = 3 -  color[node];
                    q.push(nei);
                }
                else if(color[nei] == color[node]){
                    return false;
                }


            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , 0);


        for(int i = 0; i < n ; i++){
            if(color[i] == 0){
                if(!solve(i , graph , color)){
                    return false;
                }
            }
        }
        return true;
    }
};